#include "WarBoats.h"
#include "Ocean.h"
#include <iostream> // cout, endl
#include <iomanip>  // setw

namespace CS170
{
  namespace WarBoats
  {
    const int BOAT_LENGTH = 4;  // Length of a boat
    const int HIT_OFFSET  = 100; // Add this to the boat ID
    
/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    Ocean *CreateOcean(int num_boats, int x_quadrants, int y_quadrants)
    {
      // Create an Ocean called ocean
      Ocean *ocean            = new Ocean;
      
      // Create a new array of boats
      ocean->boats            = new Boat[num_boats];
      ocean->num_boats        = num_boats;
      
      // Set the x and y of the ocean to the given values
      ocean->x_quadrants      = x_quadrants;
      ocean->y_quadrants      = y_quadrants;
      
      // Create the grid for the ocean
      ocean->grid             = new int[x_quadrants * y_quadrants];
      
      // Initialize stats
      ocean->stats.hits       = 0;
      ocean->stats.misses     = 0;
      ocean->stats.duplicates = 0;
      ocean->stats.sunk       = 0;
      
      // Initialize the ocean by zeroing it out
      for(int i = 0; i < (x_quadrants * y_quadrants); i++)
        ocean->grid[i] = 0;
    
      // Initialize the boats hits
      for(int i = 0; i < (num_boats); i++)
      {
        ocean->boats[i].hits = 0;
      }
      
      // Return the created ocean
      return ocean;
    }

/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    void DestroyOcean(Ocean *theOcean)
    {
      delete [] theOcean->grid;
      delete [] theOcean->boats;
      delete theOcean;
    }
    
/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    BoatPlacement PlaceBoat(Ocean &ocean, const Boat& boat)
    {    
      //Position in the single dimensional array of the boat (First Point)
      int ArrayPosition = (boat.position.y * ocean.x_quadrants)
                        + (boat.position.x);
      
//If boat is vertical ----------------------------------------------------------
      
      if(boat.orientation == oVERTICAL)
      {   
      
        if (boat.position.x > (ocean.x_quadrants - 1))
            return bpREJECTED;
        if (boat.position.y > (ocean.y_quadrants - 1))
            return bpREJECTED;
        
        if (boat.position.y > (ocean.y_quadrants - BOAT_LENGTH))
            return bpREJECTED;
        
        for (int i = 0; i < BOAT_LENGTH; i++)
        {
            if (ocean.grid[ArrayPosition + (i * ocean.x_quadrants)] != dtOK)
                return bpREJECTED;
        }

        for (int i = 0; i < BOAT_LENGTH; i++)
        {
            ocean.grid[ArrayPosition + (i * ocean.x_quadrants)] = boat.ID;
        }
        return bpACCEPTED;
      }
//------------------------------------------------------------------------------

//If boat is horizontal --------------------------------------------------------
       if((boat.orientation) == oHORIZONTAL)  
        {

            if (boat.position.x > (ocean.x_quadrants - 1))
                return bpREJECTED;
            if (boat.position.y > (ocean.y_quadrants - 1))
                return bpREJECTED;

            if (boat.position.x + (BOAT_LENGTH - 1) >(ocean.x_quadrants - 1))
                return bpREJECTED;
            
            for (int i = 0; i < BOAT_LENGTH; i++)
                {
                    if (ocean.grid[ArrayPosition + i] != dtOK)
                        return bpREJECTED;
                }

            for (int i = 0; i < BOAT_LENGTH; i++)
            {
                ocean.grid[ArrayPosition + i] = boat.ID;
            }
            
            return bpACCEPTED;
 
        }
//------------------------------------------------------------------------------
        return bpREJECTED;
     }

/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    ShotResult TakeShot(Ocean &ocean, const Point &coordinate)
    {
      
      //Position in the single dimensional array of the Shot
      int ArrayPosition = (coordinate.y * ocean.x_quadrants) + coordinate.x;
      int ArrayValue = ocean.grid[ArrayPosition];
      
      if (coordinate.x > (ocean.x_quadrants) || coordinate.x < 0)
        return srILLEGAL;
      if (coordinate.y >(ocean.y_quadrants) || coordinate.y < 0)
        return srILLEGAL;
      

      
//----- If the shot hit open ocean that was not previously hit -----------------
      
      if (ArrayValue == dtOK)
      {
        ocean.stats.misses++;                   // Increment stat misses
        ocean.grid[ArrayPosition] = dtBLOWNUP;  // Flag the spot as hit
        
        return srMISS;                          // Return MISS
      }
      
//----- If the shot hit the same place twice -----------------------------------
      
      if (ArrayValue == dtBLOWNUP || ArrayValue > HIT_OFFSET)
      {
        ocean.stats.duplicates++;         // Increment stat duplicates
        
        return srDUPLICATE;               // Return DUPLICATE
      }
      
//----- If the shot hit a boat -------------------------------------------------
      
      ocean.stats.hits++;
      ocean.boats[ArrayValue - 1].hits++;
      ocean.grid[ArrayPosition] += HIT_OFFSET;
      
      // And If that shot sunk a boat
      if (ocean.boats[ArrayValue - 1].hits == BOAT_LENGTH)
      {
        ocean.stats.sunk++;               // Increment stat sunk
        
        return srSUNK;                    // Return SUNK
      }
      
      return srHIT;                       // Otherwise Return HIT
    }
    
/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    ShotStats GetShotStats(const Ocean &ocean)
    {
        return ocean.stats; 
    }


/******************************************************************************/
/*!
  \brief
    Prints the grid (ocean) to the screen.
  
  \param ocean
    The Ocean to print
  
  \param field_width
    How much space each position takes when printed.
  
  \param extraline
    If true, an extra line is printed after each row. If false, no extra
    line is printed.
    
  \param showboats
    If true, the boats are shown in the output. (Debugging feature)
*/
/******************************************************************************/
    void DumpOcean(const CS170::WarBoats::Ocean &ocean,
                                    int field_width, 
                                    bool extraline, 
                                    bool showboats)
    {
      int Max_x = ocean.x_quadrants;
      int Max_y = ocean.y_quadrants;
        
        // For each row
      for (int y = 0; y < Max_y; y++)
      {
          // For each column
        for (int x = 0; x < Max_x; x++)
        {
          int value = ocean.grid[y * Max_x + x];
    
            // Is it a boat?
          if ( (value > 0) && (value < HIT_OFFSET) && (showboats == false) )
            value = 0;
    
          std::cout << std::setw(field_width) << value;
        }
        std::cout << std::endl;
        if (extraline)
          std::cout << std::endl;
      }
    }
    
  } // namespace WarBoats
} // namespace CS170



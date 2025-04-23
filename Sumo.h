#pragma once
#include <iostream>
#include <string>
#include <ostream> // Include for std::ostream

// --- Sumo Class Definition ---
// (Best practice: Place this in its own header file, e.g., "sumo.h")
class sumo
{
    // Friend function to allow direct access for printing
    friend std::ostream& operator<<(std::ostream& o, const sumo& s) // Made parameter const
    {
        o << "\n Name: " << s.ring_name << std::endl
            << " Rank: " << s.highest_rank << std::endl
            << " Wins: " << s.total_wins << std::endl;
        return o;
    }
public:
    // Default constructor
    sumo() : total_wins(0), ring_name(""), highest_rank("") {}

    // Constructor with parameters (optional but good practice)
    sumo(std::string name, std::string rank, int wins)
        : ring_name(name), highest_rank(rank), total_wins(wins) {
    }

    // Getter methods marked as const
    int getWins() const { return total_wins; }
    std::string getName() const { return ring_name; }
    std::string getRank() const { return highest_rank; }

    // Setter methods (remain non-const as they modify the object)
    void setWins(int wins) { total_wins = wins; }
    void setName(const std::string& name) { ring_name = name; } // Pass string by const reference
    void setRank(const std::string& rank) { highest_rank = rank; } // Pass string by const reference

private:
    int total_wins;
    std::string ring_name;
    std::string highest_rank;
};

template <typename T>
struct compareobj {
    // Overload the function call operator()
    // Takes two constant references to sumo objects
    bool operator()(const sumo& lhs, const sumo& rhs) const {
        // Access wins using the const getter method
        return lhs.getWins() < rhs.getWins(); // Returns true if lhs wins < rhs wins
    }
};
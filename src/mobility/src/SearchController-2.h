#ifndef SEARCH_CONTROLLER
#define SEARCH_CONTROLLER

#include <geometry_msgs/Pose2D.h>
#include <random_numbers/random_numbers.h>
#include <string>
/**
 * This class implements the search control algorithm for the rovers. The code
 * here should be modified and enhanced to improve search performance.
 */
class RoverInfo;

class SearchController {

  public:

    SearchController();

    // performs search pattern
    geometry_msgs::Pose2D search(geometry_msgs::Pose2D currentLocation, RoverInfo *rover);

    // continues search pattern after interruption
    geometry_msgs::Pose2D continueInterruptedSearch(geometry_msgs::Pose2D currentLocation, geometry_msgs::Pose2D oldGoalLocation);
    void direction();
  private:
    bool _call;
    geometry_msgs::Pose2D goalLocation;
    geometry_msgs::Pose2D currentLocation;
    random_numbers::RandomNumberGenerator* rng;
};


class RoverInfo{

public:
    bool firstRun();
    RoverInfo();
    RoverInfo(std::string rover_name);
    void setRun(bool running);
    std::string getName();
    void setName(std::string name);

private:
    bool fRun;
    std::string rName;


};
#endif /* SEARCH_CONTROLLER */

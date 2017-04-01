#include "SearchController.h"

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
}

/**
 * This code implements a basic random walk search.
 */
geometry_msgs::Pose2D SearchController::search(geometry_msgs::Pose2D currentLocation, RoverInfo *rover) {
//names: achilles, aeneas, ajax
//colors: black, yellow, white
    if(rover->getName() == "achilles"){
        this->goalLocation.theta = currentLocation.theta + 1.57;
    }else if(rover->getName() == "aeneas"){
        this->goalLocation.theta = rng->gaussian(currentLocation.theta, 0.25);
      //select new heading from Gaussian distribution around current heading
      //  if(!_call)
        //    this->direction();
        //else{
      //select new position 50 cm from current location
      this->goalLocation.x = currentLocation.x + (0.5 * cos(goalLocation.theta));
      this->goalLocation.y = currentLocation.y + (0.5 * sin(goalLocation.theta));
    }else if(rover->getName() == "ajax"){
        this->goalLocation.theta = rng->gaussian(currentLocation.theta, 0.25);
      //select new heading from Gaussian distribution around current heading
      //  if(!_call)
        //    this->direction();
        //else{
      //select new position 50 cm from current location
      this->goalLocation.x = currentLocation.x + (0.5 * cos(goalLocation.theta));
      this->goalLocation.y = currentLocation.y + (0.5 * sin(goalLocation.theta));
    }else{
        this->goalLocation.theta = rng->gaussian(currentLocation.theta, 0.25);
      //select new heading from Gaussian distribution around current heading
      //  if(!_call)
        //    this->direction();
        //else{
      //select new position 50 cm from current location
      this->goalLocation.x = currentLocation.x + (0.5 * cos(goalLocation.theta));
      this->goalLocation.y = currentLocation.y + (0.5 * sin(goalLocation.theta));
    }


    //}
  return goalLocation;
}

/**
 * Continues search pattern after interruption. For example, avoiding the
 * center or collisions.
 */
geometry_msgs::Pose2D SearchController::continueInterruptedSearch(geometry_msgs::Pose2D currentLocation, geometry_msgs::Pose2D oldGoalLocation) {
  geometry_msgs::Pose2D newGoalLocation;

  //remainingGoalDist avoids magic numbers by calculating the dist
  double remainingGoalDist = hypot(oldGoalLocation.x - currentLocation.x, oldGoalLocation.y - currentLocation.y);

  //this of course assumes random walk continuation. Change for diffrent search methods.
  newGoalLocation.theta = oldGoalLocation.theta;
  newGoalLocation.x = currentLocation.x + (0.50 * cos(oldGoalLocation.theta)); //(remainingGoalDist * cos(oldGoalLocation.theta));
  newGoalLocation.y = currentLocation.y + (0.50 * sin(oldGoalLocation.theta)); //(remainingGoalDist * sin(oldGoalLocation.theta));
  _call = false;
  this->direction();
  return newGoalLocation;
}

void SearchController::direction(){
    goalLocation.theta = (this->currentLocation.theta + 1.57);
    _call = true;

}

RoverInfo::RoverInfo(std::string rover_name){
    fRun = false;
    rName = rover_name;
}
RoverInfo::RoverInfo(){
    fRun = false;
    rName = "";
}

bool RoverInfo::firstRun(){
    return this->fRun;
}
void RoverInfo::setRun(bool running){
    fRun = running;
}
std::string RoverInfo::getName(){
    return rName;
}
void RoverInfo::setName(std::string name){
    rName = name;
}


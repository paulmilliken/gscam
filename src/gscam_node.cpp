
#include <ros/ros.h>
#include <gscam/gscam.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "gscam_publisher");
  ros::NodeHandle nh, nh_private("~");

  gscam::GSCam gscam_driver(nh, nh_private);
  // Enter slow loop to run driver in case the camera is not yet up
  while(true) {
    gscam_driver.run();
    sleep(10);
  }

  return 0;
}


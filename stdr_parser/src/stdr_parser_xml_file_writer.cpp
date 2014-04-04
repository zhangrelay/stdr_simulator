/******************************************************************************
   STDR Simulator - Simple Two DImensional Robot Simulator
   Copyright (C) 2013 STDR Simulator
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
   Authors : 
   * Manos Tsardoulias, etsardou@gmail.com
   * Aris Thallas, aris.thallas@gmail.com
   * Chris Zalidis, zalidis@gmail.com 
******************************************************************************/

#include "stdr_parser/stdr_parser_xml_file_writer.h"

namespace stdr_parser
{
  
  /**
  @brief Default constructor
  @return void
  **/
  XmlFileWriter::XmlFileWriter(void)
  {

  }

  //!<-----------------------------------------------------------------
  //!< Template declaration for stdr_msgs::Noise
  template void XmlFileWriter::messageToFile
    (stdr_msgs::Noise msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::Noise
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::Noise>
    (stdr_msgs::Noise msg,TiXmlNode* base)
  {
    //!< Create noise
    TiXmlElement* noise;
    noise = new TiXmlElement("noise");
    base->LinkEndChild(noise);
        
    //!< Create noise specifications
    TiXmlElement* noise_specs;
    noise_specs = new TiXmlElement("noise_specifications");
    noise->LinkEndChild(noise_specs);
    
    //!< Create noise mean
    TiXmlElement* noise_mean;
    noise_mean = new TiXmlElement("noise_mean");
    noise_specs->LinkEndChild(noise_mean);
    
    TiXmlText * noise_mean_text = new TiXmlText(SSTR(msg.noiseMean));
    noise_mean->LinkEndChild(noise_mean_text);
    
    //!< Create noise std
    TiXmlElement* noise_std;
    noise_std = new TiXmlElement("noise_std");
    noise_specs->LinkEndChild(noise_std);
    
    TiXmlText * noise_std_text = new TiXmlText(SSTR(msg.noiseStd));
    noise_std->LinkEndChild(noise_std_text);
  }
  
  //!------------------------------------------------------------------
  //!< Template declaration for stdr_msgs::FootprintMsg
  template void XmlFileWriter::messageToFile
    (stdr_msgs::FootprintMsg msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::Footprint
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::FootprintMsg>
    (stdr_msgs::FootprintMsg msg,TiXmlNode* base){
    //!< Create noise
    TiXmlElement* footprint;
    footprint = new TiXmlElement("footprint");
    base->LinkEndChild(footprint);
        
    //!< Create footprint specifications
    TiXmlElement* footprint_specs;
    footprint_specs = new TiXmlElement("footprint_specifications");
    footprint->LinkEndChild(footprint_specs);
    
    //!< Create footprint radius
    TiXmlElement* radius;
    radius = new TiXmlElement("radius");
    footprint_specs->LinkEndChild(radius);
    TiXmlText * radius_text = new TiXmlText(SSTR(msg.radius));
    radius->LinkEndChild(radius_text);
    
    //!< Create footprint radius
    TiXmlElement* points;
    points = new TiXmlElement("points");
    footprint_specs->LinkEndChild(points);
    
    for(unsigned int i = 0 ; i < msg.points.size() ; i++)
    {
      TiXmlElement* point;
      point = new TiXmlElement("point");
      points->LinkEndChild(point);
      
      TiXmlElement* x;
      x = new TiXmlElement("x");
      point->LinkEndChild(x);
      TiXmlText * x_text = new TiXmlText(SSTR(msg.points[i].x));
      x->LinkEndChild(x_text);
      
      TiXmlElement* y;
      y = new TiXmlElement("y");
      point->LinkEndChild(y);
      TiXmlText * y_text = new TiXmlText(SSTR(msg.points[i].y));
      y->LinkEndChild(y_text);
    }
  }
  
  //!------------------------------------------------------------------
  //!< Template specialization for geometry_msgs::Pose2D
  template <>
  void XmlFileWriter::messageToXmlElement<geometry_msgs::Pose2D>
    (geometry_msgs::Pose2D msg,TiXmlNode* base){
    //!< Create pose
    TiXmlElement* pose;
    pose = new TiXmlElement("pose");
    base->LinkEndChild(pose);
        
    //!< Create x
    TiXmlElement* x;
    x = new TiXmlElement("x");
    pose->LinkEndChild(x);
    TiXmlText * x_text = new TiXmlText(SSTR(msg.x));
    x->LinkEndChild(x_text);
    
    //!< Create y
    TiXmlElement* y;
    y = new TiXmlElement("y");
    pose->LinkEndChild(y);
    TiXmlText * y_text = new TiXmlText(SSTR(msg.y));
    y->LinkEndChild(y_text);
    
    //!< Create theta
    TiXmlElement* theta;
    theta = new TiXmlElement("theta");
    pose->LinkEndChild(theta);
    TiXmlText * theta_text = new TiXmlText(SSTR(msg.theta));
    theta->LinkEndChild(theta_text);
  }

  //!------------------------------------------------------------------
  //!< Template declaration for stdr_msgs::LaserSensorMsg
  template void XmlFileWriter::messageToFile
    (stdr_msgs::LaserSensorMsg msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::LaserSensorMsg
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::LaserSensorMsg>
    (stdr_msgs::LaserSensorMsg msg,TiXmlNode* base){
      
    //!< Create laser
    TiXmlElement* laser = new TiXmlElement("laser");
    base->LinkEndChild(laser);
        
    //!< Create laser specifications
    TiXmlElement* laser_specifications = 
      new TiXmlElement("laser_specifications");
    laser->LinkEndChild(laser_specifications);

    //!< Create max_angle
    TiXmlElement* max_angle = new TiXmlElement("max_angle");
    laser_specifications->LinkEndChild(max_angle);
    TiXmlText * max_angle_text = new TiXmlText(SSTR(msg.maxAngle));
    max_angle->LinkEndChild(max_angle_text);
    
    //!< Create min_angle
    TiXmlElement* min_angle = new TiXmlElement("min_angle");
    laser_specifications->LinkEndChild(min_angle);
    TiXmlText * min_angle_text = new TiXmlText(SSTR(msg.minAngle));
    min_angle->LinkEndChild(min_angle_text);
    
    //!< Create max_range
    TiXmlElement* max_range = new TiXmlElement("max_range");
    laser_specifications->LinkEndChild(max_range);
    TiXmlText * max_range_text = new TiXmlText(SSTR(msg.maxRange));
    max_range->LinkEndChild(max_range_text);
    
    //!< Create min_range
    TiXmlElement* min_range = new TiXmlElement("min_range");
    laser_specifications->LinkEndChild(min_range);
    TiXmlText * min_range_text = new TiXmlText(SSTR(msg.minRange));
    min_range->LinkEndChild(min_range_text);
    
    //!< Create num rays
    TiXmlElement* num_rays = new TiXmlElement("num_rays");
    laser_specifications->LinkEndChild(num_rays);
    TiXmlText * num_rays_text = new TiXmlText(SSTR(msg.numRays));
    num_rays->LinkEndChild(num_rays_text);

    //!< Create frequency
    TiXmlElement* frequency = new TiXmlElement("frequency");
    laser_specifications->LinkEndChild(frequency);
    TiXmlText * frequency_text = new TiXmlText(SSTR(msg.frequency));
    frequency->LinkEndChild(frequency_text);
    
    //!< Create frame id
    TiXmlElement* frame_id = new TiXmlElement("frame_id");
    laser_specifications->LinkEndChild(frame_id);
    TiXmlText * frame_id_text = new TiXmlText(SSTR(msg.frame_id));
    frame_id->LinkEndChild(frame_id_text);
    
    //!< Create pose
    messageToXmlElement(msg.pose,laser_specifications);
    
    //!< Create noise
    messageToXmlElement(msg.noise,laser_specifications);
  }
  
  //!------------------------------------------------------------------
  //!< Template declaration for stdr_msgs::SonarSensorMsg
  template void XmlFileWriter::messageToFile
    (stdr_msgs::SonarSensorMsg msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::SonarSensorMsg
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::SonarSensorMsg>
    (stdr_msgs::SonarSensorMsg msg,TiXmlNode* base){
      
    //!< Create sonar
    TiXmlElement* sonar = new TiXmlElement("sonar");
    base->LinkEndChild(sonar);
        
    //!< Create sonar specifications
    TiXmlElement* sonar_specifications = 
      new TiXmlElement("sonar_specifications");
    sonar->LinkEndChild(sonar_specifications);

    //!< Create cone_angle
    TiXmlElement* cone_angle = new TiXmlElement("cone_angle");
    sonar_specifications->LinkEndChild(cone_angle);
    TiXmlText * cone_angle_text = new TiXmlText(SSTR(msg.coneAngle));
    cone_angle->LinkEndChild(cone_angle_text);
    
    //!< Create max_range
    TiXmlElement* max_range = new TiXmlElement("max_range");
    sonar_specifications->LinkEndChild(max_range);
    TiXmlText * max_range_text = new TiXmlText(SSTR(msg.maxRange));
    max_range->LinkEndChild(max_range_text);
    
    //!< Create min_range
    TiXmlElement* min_range = new TiXmlElement("min_range");
    sonar_specifications->LinkEndChild(min_range);
    TiXmlText * min_range_text = new TiXmlText(SSTR(msg.minRange));
    min_range->LinkEndChild(min_range_text);
    
    //!< Create frequency
    TiXmlElement* frequency = new TiXmlElement("frequency");
    sonar_specifications->LinkEndChild(frequency);
    TiXmlText * frequency_text = new TiXmlText(SSTR(msg.frequency));
    frequency->LinkEndChild(frequency_text);
    
    //!< Create frame id
    TiXmlElement* frame_id = new TiXmlElement("frame_id");
    sonar_specifications->LinkEndChild(frame_id);
    TiXmlText * frame_id_text = new TiXmlText(SSTR(msg.frame_id));
    frame_id->LinkEndChild(frame_id_text);
    
    //!< Create pose
    messageToXmlElement(msg.pose,sonar_specifications);
    
    //!< Create noise
    messageToXmlElement(msg.noise,sonar_specifications);
  }
  
  //!------------------------------------------------------------------
  //!< Template declaration for stdr_msgs::RfidSensorMsg
  template void XmlFileWriter::messageToFile
    (stdr_msgs::RfidSensorMsg msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::RfidSensorMsg
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::RfidSensorMsg>
    (stdr_msgs::RfidSensorMsg msg,TiXmlNode* base){
      
    //!< Create rfid reader
    TiXmlElement* rfidReader = new TiXmlElement("rfid_reader");
    base->LinkEndChild(rfidReader);
        
    //!< Create rfid reader specifications
    TiXmlElement* rfid_reader_specifications = 
      new TiXmlElement("rfid_reader_specifications");
    rfidReader->LinkEndChild(rfid_reader_specifications);

    //!< Create max_range
    TiXmlElement* maxRange = new TiXmlElement("maxRange");
    rfid_reader_specifications->LinkEndChild(maxRange);
    TiXmlText * maxRange_text = new TiXmlText(SSTR(msg.maxRange));
    maxRange->LinkEndChild(maxRange_text);
    
    //!< Create angleSpan
    TiXmlElement* angleSpan = new TiXmlElement("angleSpan");
    rfid_reader_specifications->LinkEndChild(angleSpan);
    TiXmlText * angleSpan_text = new TiXmlText(SSTR(msg.angleSpan));
    angleSpan->LinkEndChild(angleSpan_text);
    
    //!< Create signalCutoff
    TiXmlElement* signalCutoff = new TiXmlElement("signalCutoff");
    rfid_reader_specifications->LinkEndChild(signalCutoff);
    TiXmlText * signalCutoff_text = new TiXmlText(SSTR(msg.signalCutoff));
    signalCutoff->LinkEndChild(signalCutoff_text);
    
    //!< Create frequency
    TiXmlElement* frequency = new TiXmlElement("frequency");
    rfid_reader_specifications->LinkEndChild(frequency);
    TiXmlText * frequency_text = new TiXmlText(SSTR(msg.frequency));
    frequency->LinkEndChild(frequency_text);
    
    //!< Create frame id
    TiXmlElement* frame_id = new TiXmlElement("frame_id");
    rfid_reader_specifications->LinkEndChild(frame_id);
    TiXmlText * frame_id_text = new TiXmlText(SSTR(msg.frame_id));
    frame_id->LinkEndChild(frame_id_text);
    
    //!< Create pose
    messageToXmlElement(msg.pose,rfid_reader_specifications);
  }
  
  //!------------------------------------------------------------------
  //!< Template declaration for stdr_msgs::RobotMsg
  template void XmlFileWriter::messageToFile
    (stdr_msgs::RobotMsg msg,std::string file_name);
    
  //!< Template specialization for stdr_msgs::RobotMsg
  template <>
  void XmlFileWriter::messageToXmlElement<stdr_msgs::RobotMsg>
    (stdr_msgs::RobotMsg msg,TiXmlNode* base){
      
    //!< Create robot
    TiXmlElement* robot = new TiXmlElement("robot");
    base->LinkEndChild(robot);
        
    //!< Create robot specifications
    TiXmlElement* robot_specifications = 
      new TiXmlElement("robot_specifications");
    robot->LinkEndChild(robot_specifications);

    //!< Create initial pose
    TiXmlElement* pose;
    pose = new TiXmlElement("initial_pose");
    robot_specifications->LinkEndChild(pose);
        
    //!< Create x
    TiXmlElement* x;
    x = new TiXmlElement("x");
    pose->LinkEndChild(x);
    TiXmlText * x_text = new TiXmlText(SSTR(msg.initialPose.x));
    x->LinkEndChild(x_text);
    
    //!< Create y
    TiXmlElement* y;
    y = new TiXmlElement("y");
    pose->LinkEndChild(y);
    TiXmlText * y_text = new TiXmlText(SSTR(msg.initialPose.y));
    y->LinkEndChild(y_text);
    
    //!< Create theta
    TiXmlElement* theta;
    theta = new TiXmlElement("theta");
    pose->LinkEndChild(theta);
    TiXmlText * theta_text = new TiXmlText(SSTR(msg.initialPose.theta));
    theta->LinkEndChild(theta_text);
    
    //!< Create footprint
    messageToXmlElement(msg.footprint,robot_specifications);
    
    //!< Create lasers
    for(unsigned int i = 0 ; i < msg.laserSensors.size() ; i++)
    {
      messageToXmlElement(msg.laserSensors[i],robot_specifications);
    }
    
    //!< Create sonars
    for(unsigned int i = 0 ; i < msg.sonarSensors.size() ; i++)
    {
      messageToXmlElement(msg.sonarSensors[i],robot_specifications);
    }
    
    //!< Create rfid readers
    for(unsigned int i = 0 ; i < msg.rfidSensors.size() ; i++)
    {
      messageToXmlElement(msg.rfidSensors[i],robot_specifications);
    }
  }
  
  //!<-----------------------------------------------------------------
  
  /**
  @brief Creates an xml element from a msg - template member function
  @param msg [T] The message
  @param base [TiXmlNode*] The xml node to write the message
  @return void
  **/
  template <class T>
  void XmlFileWriter::messageToXmlElement(T msg,TiXmlNode* base)
  {
  }
  
  /**
  @brief Creates an xml file from a message - template member function
  @param msg [T] The message
  @param file_name [std::string] The xml file name to write the message
  @return void
  **/
  template <class T>
  void XmlFileWriter::messageToFile(T msg,std::string file_name)
  {
    TiXmlDocument doc;
    messageToXmlElement<T>(msg,&doc);
    doc.SaveFile(file_name.c_str()); 
  }
}


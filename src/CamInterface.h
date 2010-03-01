/*
 *
 * German Research Center for Artificial Intelligence
 * DFKI-Lab Bremen 2010
 *
 * File:   CamInterface.h
 * Author: Alexander Duda (Alexander.Duda@dfki.de)
 *
 */

#ifndef _CAMINTERFACE_H
#define	_CAMINTERFACE_H

#include "CamTypes.h"               //definition of camera specific types
#include "CameraFrame.h"     	    //definition of a general image frame
#include <vector>
#include <stdexcept>

namespace camera
{
    //! Virtual class which declares an general interface for imaging sensors.
    /*! Use this class as base class if you want to add your own sensor.
    */
    class CamInterface
    {
    protected:
        frame_size_t image_size_;  //size of the returned image frame
        frame_mode_t image_mode_;  //color mode of the returned image frame
                                   //See CameraFrame.h for all possible modes
        uint8_t image_color_depth_;//color depth in bits of the returned image
                                   //frame
        GrabMode act_grab_mode_;  //actual grab mode
    public:
        CamInterface();
        virtual ~CamInterface();

    private:
        CamInterface(const CamInterface &other){}; //only one handle for
                                                   //one camera is allowed

    // ------------------------------------------------------------------------
    // CONTROL FUNCTIONS-------------------------------------------------------
    // ------------------------------------------------------------------------

    public:
        //! Lists all available cameras
        /*!
          \param cam_infos vector of all available cameras
          \return number of listed cameras
        */
        virtual int listCameras(std::vector<CamInfo> &cam_infos)const = 0;

        //! Returns information about the first camera that matches the pattern
        /*!
          \param pattern camera pattern
          \param cam structure where the camera information is stored
          \return returns false if no camera matches
        */
        virtual bool findCamera(const CamInfo &pattern,CamInfo &cam )const;

         //! Counts the number of available cameras
        /*!
          \return number of available cameras
        */
        virtual int countCameras()const;


        //! Opens a specific camera
        /*!
          \param cam camera which shall be opened
          \param mode connection mode (eMaster, eMonitor)
          \return returns true if the camera is open after the call
        */
        virtual bool open(const CamInfo &cam,const AccessMode mode=Master)=0;

        //! Opens the first camera that matches the pattern
        /*! This functions uses findCamera() and open() to open the camera.
          \param display_name display name of the camera
          \param mode connection mode (eMaster, eMonitor)
          \return returns true if the camera is open after the call
        */
        bool open2(const std::string &display_name,const AccessMode mode=Master);

         //! Opens the first camera that matches the pattern
         /*! This functions uses findCamera() and open() to open the camera.
          \param pattern camera pattern
          \param mode connection mode (eMaster, eMonitor)
          \return returns true if the camera is open after the call
        */
        bool open2(const CamInfo &pattern,const AccessMode mode=Master);
        
        //! Checks if the camera is open
        /*!
          \return returns true if the camera is open
        */
        virtual bool isOpen()const = 0;

         //! Closes the camera
        /*!
          \return returns true if no camera is open or the camera was closed
        */
        virtual bool close()=0;

        //! Starts capturing into a buffer
        /*!
          \param mode capturing mode (SingleFrame, MultiFrame, Continuously)
          \param buffer_len length of the buffer in frames.
          \return returns true if capturing was started
        */
        virtual bool grab(const GrabMode mode = SingleFrame,
                          const int buffer_len=1)=0;

        //! Retrieves the next frame from the buffer (no data are copied).
        /*! This function is synchron and blocks until a frame can be retrieved
            from the buffer or a timeout occurs. To check if a frame can be
            retrievt call isFrameAvailable().
          \param frame structure where the frame is stored.
          \param buffer_len length of the buffer in frames.
          \return returns true if a frame was retrieved
          \attention The frame must have the same size like the returned frame
            because the function swaps the image vector and does not copy
            any data. Therfore any stored pointer to the vector data are no more
            valid after calling the function.
        */
        virtual bool retrieveFrame(Frame &frame,const int timeout=1000)=0;

         //! Checks if a frame can be retrieved from the buffer
        /*!
          \return returns true if a frame can be retrieved without blocking
        */
        virtual bool isFrameAvailable()=0;

         //! Skips all buffered frame beside the last one.
        /*!
          \return returns the number of skipped frames
        */
        virtual int skipFrames(){return 0;};

         //! Sets the IP adress and subnetmask of a ethernet camera
        /*!
          \param cam camera whose ip settings shall be changed
          \param ip_settings ip settings to be set.
          \return returns true if the change was succesfull
        */
        virtual bool setIpSettings(const CamInfo &cam,
                    const IPSettings &ip_settings)const{return false;};

         //! Sets the value of an integer attribute.
        /*!
          \param attrib identifier of the attribute to be changed
          \param value new integer value.
          \return returns true if the change was succesfull
        */
        virtual bool setAttrib(const int_attrib::CamAttrib attrib,const int value)
                        {return false;};

          //! Sets the value of a double attribute.
        /*!
          \param attrib identifier of the attribute to be changed
          \param value new double value.
          \return returns true if the change was succesfull
        */
        virtual bool setAttrib(const double_attrib::CamAttrib attrib,
                                const double value){return false;};

        //! Sets the value of a string attribute.
        /*!
          \param attrib identifier of the attribute to be changed
          \param value new string value.
          \return returns true if the change was succesfull
        */
        virtual bool setAttrib(const str_attrib::CamAttrib attrib,
                        const std::string &value){return false;};

         //! Sets the value of an enum attribute.
        /*!
          \param attrib identifier of the attribute to be changed
          \param value new enum value.
          \return returns true if the change was succesfull
        */
        virtual bool setAttrib(const enum_attrib::CamAttrib attrib)
                                        {return false;};

        //! Checks if an integer attribute is available
        /*!
          \param attrib identifier of the attribute to be checked
          \return returns true if the attribute is available
        */
        virtual bool isAttribAvail(const int_attrib::CamAttrib attrib)
                            {return false;};

        //! Checks if a double attribute is available
        /*!
          \param attrib identifier of the attribute to be checked
          \return returns true if the attribute is available
        */
        virtual bool isAttribAvail(const double_attrib::CamAttrib attrib)
                    {return false;};

        //! Checks if a string attribute is available
        /*!
          \param attrib identifier of the attribute to be checked
          \return returns true if the attribute is available
        */
        virtual bool isAttribAvail(const str_attrib::CamAttrib attrib)
                            {return false;};

        //! Returns the value of an integer attribute
        /*!
          \param attrib identifier of the attribute
          \return attribute value
        */
        virtual int getAttrib(const int_attrib::CamAttrib attrib){return 0;};

        //! Returns the value of a double attribute
        /*!
          \param attrib identifier of the attribute
          \return attribute value
        */
        virtual double getAttrib(const double_attrib::CamAttrib attrib){return 0;};

        //! Returns the value of a string attribute
        /*!
          \param attrib identifier of the attribute
          \return attribute value
        */
        virtual std::string getAttrib(const str_attrib::CamAttrib attrib)
                        {return "";};

        //! Checks if the enum attribute is set
        /*!
          \param attrib identifier of the attribute
          \return returns true if the enum attribute is set
        */
        virtual bool isAttribSet(const enum_attrib::CamAttrib attrib)
                        {return false;};

        //! Retrieves a camera frame (no data are copied)
        /*! If grab is called in advance the operator is equal to the function
            retrieveFrame(). Otherwise the function calls grab(eSingleFrame,1)
            and retrieveFrame().
          \param frame structure where the frame is stored.
          \attention The frame must have the same size like the returned frame
            because the function swaps the image vector and does not copy
            any data. Therfore any stored pointer to the vector data are no more
            valid after calling the function.
        */
        CamInterface& operator>>(Frame &frame);

        //! Sets the frame settings size, mode and color depth.
        /*!
          \param size size of the frame in pixel
          \param mode color mode of the frame (MODE_GRAYSCALE,MODE_RGB,...)
          \param color_depth number of bytes per pixel
          \param resize_frames resizes all buffered frame to the right size
          \return returns true if the settings were set succsessfully
        */
        virtual bool setFrameSettings(const frame_size_t size,
                                      const frame_mode_t mode,
                                      const uint8_t color_depth,
                                      const bool resize_frames = true);

         //! Sets the camera frame settings to the values of the frame.
        /*!
          \param frame frame which descripes the settings to be set
          \param resize_frames resizes all buffered frame to the right size
          \return returns true if the settings were set succsessfully
        */
        virtual bool setFrameSettings(const Frame &frame,
                                    const bool resize_frames = true);

        //! Gets the actual frame settings size, mode and color depth.
        /*!
          \param size size of the frame in pixel
          \param mode color mode of the frame (MODE_GRAYSCALE,MODE_RGB,...)
          \param color_depth number of bytes per pixel
          \return returns false if no camera is opened
        */
        virtual bool getFrameSettings(frame_size_t &size,
                                        frame_mode_t &mode,
                                        uint8_t &color_depth)
        {return false;};

        //! Triggers a new frame if FrameStartTriggerMode is set to Software.
        /*!
          \return returns false if no camera is opened
        */
        virtual bool triggerFrame(){return false;};

        //! Sets the camera to default settings.
        /*!
          \return returns false if no camera is opened
        */
        virtual bool setToDefault(){return false;};

        //! Configures the frame that it matches the camera frame settings.
        /*!
          \param frame frame to be configured
          \return returns false if no camera is opened
        */
        bool setFrameToCameraFrameSettings(Frame &frame);
    };
}
#endif	/* _CAMINTERFACE_H */

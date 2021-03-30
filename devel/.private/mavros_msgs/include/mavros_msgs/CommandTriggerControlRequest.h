// Generated by gencpp from file mavros_msgs/CommandTriggerControlRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H
#define MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mavros_msgs
{
template <class ContainerAllocator>
struct CommandTriggerControlRequest_
{
  typedef CommandTriggerControlRequest_<ContainerAllocator> Type;

  CommandTriggerControlRequest_()
    : trigger_enable(false)
    , sequence_reset(false)
    , trigger_pause(false)  {
    }
  CommandTriggerControlRequest_(const ContainerAllocator& _alloc)
    : trigger_enable(false)
    , sequence_reset(false)
    , trigger_pause(false)  {
  (void)_alloc;
    }



   typedef uint8_t _trigger_enable_type;
  _trigger_enable_type trigger_enable;

   typedef uint8_t _sequence_reset_type;
  _sequence_reset_type sequence_reset;

   typedef uint8_t _trigger_pause_type;
  _trigger_pause_type trigger_pause;





  typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CommandTriggerControlRequest_

typedef ::mavros_msgs::CommandTriggerControlRequest_<std::allocator<void> > CommandTriggerControlRequest;

typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest > CommandTriggerControlRequestPtr;
typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest const> CommandTriggerControlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator1> & lhs, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator2> & rhs)
{
  return lhs.trigger_enable == rhs.trigger_enable &&
    lhs.sequence_reset == rhs.sequence_reset &&
    lhs.trigger_pause == rhs.trigger_pause;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator1> & lhs, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5231f3f21be52f9682a8e030770339a5";
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5231f3f21be52f96ULL;
  static const uint64_t static_value2 = 0x82a8e030770339a5ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/CommandTriggerControlRequest";
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"bool    trigger_enable\n"
"bool    sequence_reset\n"
"bool    trigger_pause\n"
;
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.trigger_enable);
      stream.next(m.sequence_reset);
      stream.next(m.trigger_pause);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommandTriggerControlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>& v)
  {
    s << indent << "trigger_enable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.trigger_enable);
    s << indent << "sequence_reset: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sequence_reset);
    s << indent << "trigger_pause: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.trigger_pause);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H
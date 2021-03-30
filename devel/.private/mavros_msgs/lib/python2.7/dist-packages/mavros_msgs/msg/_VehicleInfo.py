# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/VehicleInfo.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class VehicleInfo(genpy.Message):
  _md5sum = "68ac9e63349db04d0cf8dd45a9a5b283"
  _type = "mavros_msgs/VehicleInfo"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """# Vehicle Info msg

std_msgs/Header header

uint8 HAVE_INFO_HEARTBEAT = 1
uint8 HAVE_INFO_AUTOPILOT_VERSION = 2
uint8 available_info		# Bitmap shows what info is available

# Vehicle address
uint8 sysid                     # SYSTEM ID
uint8 compid                    # COMPONENT ID

# -*- Heartbeat info -*-
uint8 autopilot                 # MAV_AUTOPILOT
uint8 type                      # MAV_TYPE
uint8 system_status             # MAV_STATE
uint8 base_mode
uint32 custom_mode
string mode                     # MAV_MODE string
uint32 mode_id                  # MAV_MODE number

# -*- Autopilot version -*-
uint64 capabilities             # MAV_PROTOCOL_CAPABILITY
uint32 flight_sw_version        # Firmware version number
uint32 middleware_sw_version    # Middleware version number
uint32 os_sw_version            # Operating system version number
uint32 board_version            # HW / board version (last 8 bytes should be silicon ID, if any)
uint16 vendor_id                # ID of the board vendor
uint16 product_id               # ID of the product
uint64 uid                      # UID if provided by hardware

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id
"""
  # Pseudo-constants
  HAVE_INFO_HEARTBEAT = 1
  HAVE_INFO_AUTOPILOT_VERSION = 2

  __slots__ = ['header','available_info','sysid','compid','autopilot','type','system_status','base_mode','custom_mode','mode','mode_id','capabilities','flight_sw_version','middleware_sw_version','os_sw_version','board_version','vendor_id','product_id','uid']
  _slot_types = ['std_msgs/Header','uint8','uint8','uint8','uint8','uint8','uint8','uint8','uint32','string','uint32','uint64','uint32','uint32','uint32','uint32','uint16','uint16','uint64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,available_info,sysid,compid,autopilot,type,system_status,base_mode,custom_mode,mode,mode_id,capabilities,flight_sw_version,middleware_sw_version,os_sw_version,board_version,vendor_id,product_id,uid

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(VehicleInfo, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.available_info is None:
        self.available_info = 0
      if self.sysid is None:
        self.sysid = 0
      if self.compid is None:
        self.compid = 0
      if self.autopilot is None:
        self.autopilot = 0
      if self.type is None:
        self.type = 0
      if self.system_status is None:
        self.system_status = 0
      if self.base_mode is None:
        self.base_mode = 0
      if self.custom_mode is None:
        self.custom_mode = 0
      if self.mode is None:
        self.mode = ''
      if self.mode_id is None:
        self.mode_id = 0
      if self.capabilities is None:
        self.capabilities = 0
      if self.flight_sw_version is None:
        self.flight_sw_version = 0
      if self.middleware_sw_version is None:
        self.middleware_sw_version = 0
      if self.os_sw_version is None:
        self.os_sw_version = 0
      if self.board_version is None:
        self.board_version = 0
      if self.vendor_id is None:
        self.vendor_id = 0
      if self.product_id is None:
        self.product_id = 0
      if self.uid is None:
        self.uid = 0
    else:
      self.header = std_msgs.msg.Header()
      self.available_info = 0
      self.sysid = 0
      self.compid = 0
      self.autopilot = 0
      self.type = 0
      self.system_status = 0
      self.base_mode = 0
      self.custom_mode = 0
      self.mode = ''
      self.mode_id = 0
      self.capabilities = 0
      self.flight_sw_version = 0
      self.middleware_sw_version = 0
      self.os_sw_version = 0
      self.board_version = 0
      self.vendor_id = 0
      self.product_id = 0
      self.uid = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7BI().pack(_x.available_info, _x.sysid, _x.compid, _x.autopilot, _x.type, _x.system_status, _x.base_mode, _x.custom_mode))
      _x = self.mode
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_IQ4I2HQ().pack(_x.mode_id, _x.capabilities, _x.flight_sw_version, _x.middleware_sw_version, _x.os_sw_version, _x.board_version, _x.vendor_id, _x.product_id, _x.uid))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 11
      (_x.available_info, _x.sysid, _x.compid, _x.autopilot, _x.type, _x.system_status, _x.base_mode, _x.custom_mode,) = _get_struct_7BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.mode = str[start:end].decode('utf-8')
      else:
        self.mode = str[start:end]
      _x = self
      start = end
      end += 40
      (_x.mode_id, _x.capabilities, _x.flight_sw_version, _x.middleware_sw_version, _x.os_sw_version, _x.board_version, _x.vendor_id, _x.product_id, _x.uid,) = _get_struct_IQ4I2HQ().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7BI().pack(_x.available_info, _x.sysid, _x.compid, _x.autopilot, _x.type, _x.system_status, _x.base_mode, _x.custom_mode))
      _x = self.mode
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_IQ4I2HQ().pack(_x.mode_id, _x.capabilities, _x.flight_sw_version, _x.middleware_sw_version, _x.os_sw_version, _x.board_version, _x.vendor_id, _x.product_id, _x.uid))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 11
      (_x.available_info, _x.sysid, _x.compid, _x.autopilot, _x.type, _x.system_status, _x.base_mode, _x.custom_mode,) = _get_struct_7BI().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.mode = str[start:end].decode('utf-8')
      else:
        self.mode = str[start:end]
      _x = self
      start = end
      end += 40
      (_x.mode_id, _x.capabilities, _x.flight_sw_version, _x.middleware_sw_version, _x.os_sw_version, _x.board_version, _x.vendor_id, _x.product_id, _x.uid,) = _get_struct_IQ4I2HQ().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_IQ4I2HQ = None
def _get_struct_IQ4I2HQ():
    global _struct_IQ4I2HQ
    if _struct_IQ4I2HQ is None:
        _struct_IQ4I2HQ = struct.Struct("<IQ4I2HQ")
    return _struct_IQ4I2HQ
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_7BI = None
def _get_struct_7BI():
    global _struct_7BI
    if _struct_7BI is None:
        _struct_7BI = struct.Struct("<7BI")
    return _struct_7BI

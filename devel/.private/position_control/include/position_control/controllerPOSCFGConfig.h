//#line 2 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the position_control package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __position_control__CONTROLLERPOSCFGCONFIG_H__
#define __position_control__CONTROLLERPOSCFGCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace position_control
{
  class controllerPOSCFGConfigStatics;

  class controllerPOSCFGConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(controllerPOSCFGConfig &config, const controllerPOSCFGConfig &max, const controllerPOSCFGConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const controllerPOSCFGConfig &config1, const controllerPOSCFGConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, controllerPOSCFGConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const controllerPOSCFGConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, controllerPOSCFGConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const controllerPOSCFGConfig &config) const = 0;
      virtual void getValue(const controllerPOSCFGConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T controllerPOSCFGConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T controllerPOSCFGConfig::* field;

      virtual void clamp(controllerPOSCFGConfig &config, const controllerPOSCFGConfig &max, const controllerPOSCFGConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const controllerPOSCFGConfig &config1, const controllerPOSCFGConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, controllerPOSCFGConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const controllerPOSCFGConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, controllerPOSCFGConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const controllerPOSCFGConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const controllerPOSCFGConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, controllerPOSCFGConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, controllerPOSCFGConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(controllerPOSCFGConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);


      }
    }

    

    bool state;
    std::string name;

    class GROUP_CONTROLLER_GAINS
{
  public:
    GROUP_CONTROLLER_GAINS()
    {
      state = true;
      name = "group_controller_gains";
    }

    void setParams(controllerPOSCFGConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("new_controller_gains"==(*_i)->name){new_controller_gains = boost::any_cast<bool>(val);}
        if("kz"==(*_i)->name){kz = boost::any_cast<double>(val);}
        if("kvz"==(*_i)->name){kvz = boost::any_cast<double>(val);}
        if("kx"==(*_i)->name){kx = boost::any_cast<double>(val);}
        if("kvx"==(*_i)->name){kvx = boost::any_cast<double>(val);}
        if("ky"==(*_i)->name){ky = boost::any_cast<double>(val);}
        if("kvy"==(*_i)->name){kvy = boost::any_cast<double>(val);}
        if("ktheta"==(*_i)->name){ktheta = boost::any_cast<double>(val);}
        if("kphi"==(*_i)->name){kphi = boost::any_cast<double>(val);}
        if("kpsi"==(*_i)->name){kpsi = boost::any_cast<double>(val);}
      }
    }

    bool new_controller_gains;
double kz;
double kvz;
double kx;
double kvx;
double ky;
double kvy;
double ktheta;
double kphi;
double kpsi;

    bool state;
    std::string name;

    
}group_controller_gains;

}groups;



//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      bool new_controller_gains;
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kz;
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kvz;
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kx;
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kvx;
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double ky;
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kvy;
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double ktheta;
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kphi;
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      double kpsi;
//#line 228 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("controllerPOSCFGConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const controllerPOSCFGConfig &__max__ = __getMax__();
      const controllerPOSCFGConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const controllerPOSCFGConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const controllerPOSCFGConfig &__getDefault__();
    static const controllerPOSCFGConfig &__getMax__();
    static const controllerPOSCFGConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const controllerPOSCFGConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void controllerPOSCFGConfig::ParamDescription<std::string>::clamp(controllerPOSCFGConfig &config, const controllerPOSCFGConfig &max, const controllerPOSCFGConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class controllerPOSCFGConfigStatics
  {
    friend class controllerPOSCFGConfig;

    controllerPOSCFGConfigStatics()
    {
controllerPOSCFGConfig::GroupDescription<controllerPOSCFGConfig::DEFAULT, controllerPOSCFGConfig> Default("Default", "", 0, 0, true, &controllerPOSCFGConfig::groups);
controllerPOSCFGConfig::GroupDescription<controllerPOSCFGConfig::DEFAULT::GROUP_CONTROLLER_GAINS, controllerPOSCFGConfig::DEFAULT> group_controller_gains("group_controller_gains", "", 0, 1, true, &controllerPOSCFGConfig::DEFAULT::group_controller_gains);
//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.new_controller_gains = 0;
//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.new_controller_gains = 1;
//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.new_controller_gains = 0;
//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<bool>("new_controller_gains", "bool", 1, "change controller gains", "", &controllerPOSCFGConfig::new_controller_gains)));
//#line 34 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<bool>("new_controller_gains", "bool", 1, "change controller gains", "", &controllerPOSCFGConfig::new_controller_gains)));
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kz = 0.0;
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kz = 15.0;
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kz = 10.0;
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kz", "double", 8, "k-z", "", &controllerPOSCFGConfig::kz)));
//#line 47 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kz", "double", 8, "k-z", "", &controllerPOSCFGConfig::kz)));
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kvz = 0.0;
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kvz = 10.0;
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kvz = 5.0;
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvz", "double", 8, "k-zd", "", &controllerPOSCFGConfig::kvz)));
//#line 48 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvz", "double", 8, "k-zd", "", &controllerPOSCFGConfig::kvz)));
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kx = 0.0;
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kx = 5.0;
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kx = 3.9;
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kx", "double", 8, "k-x", "", &controllerPOSCFGConfig::kx)));
//#line 50 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kx", "double", 8, "k-x", "", &controllerPOSCFGConfig::kx)));
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kvx = 0.0;
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kvx = 5.0;
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kvx = 2.985;
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvx", "double", 8, "k-xd", "", &controllerPOSCFGConfig::kvx)));
//#line 51 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvx", "double", 8, "k-xd", "", &controllerPOSCFGConfig::kvx)));
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.ky = 0.0;
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.ky = 4.0;
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.ky = 4.0;
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("ky", "double", 8, "k-y", "", &controllerPOSCFGConfig::ky)));
//#line 52 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("ky", "double", 8, "k-y", "", &controllerPOSCFGConfig::ky)));
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kvy = 0.0;
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kvy = 4.0;
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kvy = 3.05;
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvy", "double", 8, "k-yd", "", &controllerPOSCFGConfig::kvy)));
//#line 53 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kvy", "double", 8, "k-yd", "", &controllerPOSCFGConfig::kvy)));
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.ktheta = 0.0;
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.ktheta = 6.75;
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.ktheta = 5.25;
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("ktheta", "double", 8, "k-theta", "", &controllerPOSCFGConfig::ktheta)));
//#line 62 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("ktheta", "double", 8, "k-theta", "", &controllerPOSCFGConfig::ktheta)));
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kphi = 0.0;
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kphi = 6.75;
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kphi = 5.25;
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kphi", "double", 8, "k-phi", "", &controllerPOSCFGConfig::kphi)));
//#line 64 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kphi", "double", 8, "k-phi", "", &controllerPOSCFGConfig::kphi)));
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __min__.kpsi = 0.0;
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __max__.kpsi = 3.0;
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __default__.kpsi = 1.0;
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      group_controller_gains.abstract_parameters.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kpsi", "double", 8, "k-psi", "", &controllerPOSCFGConfig::kpsi)));
//#line 66 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      __param_descriptions__.push_back(controllerPOSCFGConfig::AbstractParamDescriptionConstPtr(new controllerPOSCFGConfig::ParamDescription<double>("kpsi", "double", 8, "k-psi", "", &controllerPOSCFGConfig::kpsi)));
//#line 124 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      group_controller_gains.convertParams();
//#line 124 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.groups.push_back(controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr(new controllerPOSCFGConfig::GroupDescription<controllerPOSCFGConfig::DEFAULT::GROUP_CONTROLLER_GAINS, controllerPOSCFGConfig::DEFAULT>(group_controller_gains)));
//#line 124 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr(new controllerPOSCFGConfig::GroupDescription<controllerPOSCFGConfig::DEFAULT::GROUP_CONTROLLER_GAINS, controllerPOSCFGConfig::DEFAULT>(group_controller_gains)));
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr(new controllerPOSCFGConfig::GroupDescription<controllerPOSCFGConfig::DEFAULT, controllerPOSCFGConfig>(Default)));
//#line 366 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<controllerPOSCFGConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    controllerPOSCFGConfig __max__;
    controllerPOSCFGConfig __min__;
    controllerPOSCFGConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const controllerPOSCFGConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static controllerPOSCFGConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &controllerPOSCFGConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const controllerPOSCFGConfig &controllerPOSCFGConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const controllerPOSCFGConfig &controllerPOSCFGConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const controllerPOSCFGConfig &controllerPOSCFGConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<controllerPOSCFGConfig::AbstractParamDescriptionConstPtr> &controllerPOSCFGConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<controllerPOSCFGConfig::AbstractGroupDescriptionConstPtr> &controllerPOSCFGConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const controllerPOSCFGConfigStatics *controllerPOSCFGConfig::__get_statics__()
  {
    const static controllerPOSCFGConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = controllerPOSCFGConfigStatics::get_instance();

    return statics;
  }

//#line 11 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      const int controllerPOSCFG_ENABLE_CTRL = 1;
//#line 14 "/home/fechec/feng_ws/src/position_control/cfg/controllerPOSCFG.cfg"
      const int controllerPOSCFG_CONTROLLER_GAIN = 8;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __CONTROLLERPOSCFGRECONFIGURATOR_H__
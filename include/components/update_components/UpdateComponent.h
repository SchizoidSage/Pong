#ifndef UPDATE_COMPONENT_202304021721_H
#define UPDATE_COMPONENT_202304021721_H

class UpdateComponent : public Component
{
public:
  UpdateComponent(Actor* owner, int update_order = 100)
    : Component{ owner },
      m_update_order{ update_order }
  { }

  virtual void update(float delta_time) = 0;
  virtual void accept(UpdateComponentVisitor* visitor) = 0;
private:
  int m_update_order{ };
};

#endif
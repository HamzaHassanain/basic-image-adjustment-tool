#pragma once

template <typename Event>
class Subscriber
{
public:
    virtual void Notify(Event &event) = 0;
};
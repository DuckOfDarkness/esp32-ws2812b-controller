#ifndef EFFECT_H
#define EFFECT_H

// Enable to place various effects in the ThreadHandler

class Effect {
public:
    virtual void start() = 0;  
    virtual void stop() = 0; 
    virtual ~Effect() {}       
};

#endif

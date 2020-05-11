#ifndef MOVE
#define MOVE
//#include"Vector3D.h"

#define g 9.81
#define PI 3.1415927
#define A 400
#define F 1200
#define AF 800
#define PLUS 50000
#define NEG 20000
#define FLY 0.01
#define DIM_LG 0.8
#define DIM_LA 0.6
#define DIM_SD 1
#define DIM_SA 0.9272
#define SCALE 10

float aSpeed[PLUS+NEG];

float aCurve [8]={1.0, 0.99, 0.975, 0.952, 0.918, 0.867, 0.791, 0.677};

/***********************************************************************/
class position{
  Vector3D fVector3d;
  Vector3D rVector3d;
  
public:
  position(){};
  position(position& p){
    setX1(p.getX1());
    setY1(p.getY1());
    setZ1(p.getZ1());
    setX2(p.getX2());
    setY2(p.getY2());
    setZ2(p.getZ2());
  };

  float getX1(){return fVector3d.x;};
  float getY1(){return fVector3d.y;};
  float getZ1(){return fVector3d.z;};
  float getX2(){return rVector3d.x;};
  float getY2(){return rVector3d.y;};
  float getZ2(){return rVector3d.z;};
  
  position operator= (position  p);
  
  void setX1(float d){fVector3d.x=d;};
  void setY1(float d){fVector3d.y=d;};
  void setZ1(float d){fVector3d.z=d;};
  void setX2(float d){rVector3d.x=d;};
  void setY2(float d){rVector3d.y=d;};
  void setZ2(float d){rVector3d.z=d;};
  
  void setRear(float a, float b, float c){
    rVector3d.x=a;
    rVector3d.y=b;
    rVector3d.z=c;
  };
  static void setRear(position * p, float dir, float slope){
    p->setX2(p->getX1()+DIM_LG*cos(dir-DIM_SA));
    p->setZ2(p->getZ1()+DIM_LG*sin(dir-DIM_SA));
    p->setY2(p->getY1());
    // A MODIFIER lorsque la methode rendant la hauteur du terrain sera prete
  };

};

/***********************************************************************/
class PhysicalEngine{
  

public:
  //convert degrees to radians
  static float deg2rad(float degre){return 2*PI*degre/360;}


  //returns the most tightened curve you can pass for the speed t
  //by trying to take a more tightened curve you will spin round
  static int limit(int t){
    if(t>=NEG){
      if(aSpeed[t]<25) return 7;
      if(aSpeed[t]<32) return 6;
      if(aSpeed[t]<39) return 5;
      if(aSpeed[t]<46) return 4;
      if(aSpeed[t]<53) return 3;
      return 2;    
    }
    else{
      if(aSpeed[t]<-12) return 3;
      return 7;
    }
  }

  
  static int speed(int t, int a, int f, float r, int v)
  { //t:time index, a:throttle, f:brake, r:slope (radius)
    //r>0 down & r<0 up
    int modif=0;
    v=(int)fabs(v);
    if(r!=0){
      if(r>0)//down, greater acceleration & worst braking
	{
	  modif=(int)(60*sin(r)*60*sqrt(sin(r)));
	}
      else if(r<0){
	modif=(int)(60*sin(r)*60*sqrt(sin(-1*r)));
      }
    }
    if(a>0&&f<=0){//throttle
      if(t<NEG){
	return (int) (((t +0.5*F+(int)(0.5*modif)-NEG)) *aCurve[v]+NEG);
      }
      if(t>=PLUS+NEG-A-modif) {
	return (int) ((0.9 * (PLUS+NEG) * aCurve[v] ));
      }
      if(t<PLUS+NEG-A-modif)
	return (int) (((t+A+(int)(0.5*modif)-NEG))*aCurve[v]+NEG);
    }
    else{//throttle & brake || no throttle & no brake)
      if((a>0&&f>0)||(a<=0&&f<=0)){
	if(t<(AF-2*modif+NEG)) return NEG;
	//else if(t>PLUS-AF-2*modif) return (int) (65000*aCurve[v]);
	return (int) ((t -AF+2*modif) * aCurve[v]);
      }
      else{//brake
	if(a<=0&&f>0){
	  if(t>NEG){
	    if(t<NEG + F-0.8*modif) return (int) (NEG * aCurve[v]);
	    return (int) ((t -F+(int)(0.8*modif)) * aCurve[v]);
	  }
	  else if(t<0.5*F-0.5*modif) return (int) (NEG*0.1);
	  return (int) ((t -0.5*F+(int)(0.5*modif))*aCurve[v]);
	}
	return 0;
      }
    }  
  }

  static float distance(int v0, int v1)
  {
    float v=(aSpeed[v0]+aSpeed[v1])/(2*3.6);//pour passer en m/s
    float dist=v*0.01;// 5/100 sec
    return dist;
  }
  
  static void place(position * p0, int t, int a, int f, float r, int v, float * dir ){
    //p0=current position, t=speed index, a=throttle(1=y,0=n),
    //f=brake, r= slope (radius), v=bend, dir=direction (radius)
    //position p;
    //p=p0;
    float bend=0;

    switch(v){
    case 0:
      break;
    case 1:
      bend=0.3927; //0.3927 r = 22.5 °
      break;
    case 2:
      bend=0.7854;
      break;
    case 3:
      bend=1.1781;
      break;
    case 4:
      bend=1.5708;
      break;
    case 5:
      bend=1.9635;
      break;
    case 6:
      bend=2.3562;
      break;
    case 7:
      bend=2.7489;
      break;
    case -1:
      bend=-0.3927; //0.3927 r = 22.5 °
      break;
    case -2:
      bend=-0.5236;
      break;
    case -3:
      bend=-1.1781;
      break;
    case -4:
      bend=-1.5708;
      break;
    case -5:
      bend=-1.96356;
      break;
    case -6:
      bend=-2.3562;
      break;
    case -7:
      bend=-2.7489;
      break;
    default:
      bend=0;      
    }


    int vv=0;
    float dist=0.0;

    vv=speed(t,a,f,r,(int)fabs(v));
    dist=PhysicalEngine::distance(vv,t);
    p0->setX1(p0->getX1()+(float)(SCALE*dist*cos(*dir-bend)));
    p0->setZ1(p0->getZ1()+(float)(SCALE*dist*sin(*dir-bend)));
    //ICI il faut mettre a jour la hauteur quand on aura la methode
    position::setRear(p0,*dir,r);
    *dir=*dir-bend;
  
    //return p0;
  }

  static void spinRound(position p, float dir, int curve, float slope)
  {
    int i=0;
    int nb=10;
    //int x=0;
    //int y=0;
    int l=1;//module

    //    printf("d=%1.3f c=%d\n", *dir, * curve);
    //curve>0 -> turn right -> clock round
    float step=PI/nb;
    if(curve>=0) step=-step;
    for(i=0;i<nb;i++){//step to complete spin round
      //step = 180 / 10 || PI/10
      p.setX2(l*cos(step)+p.getX1());
      p.setZ2(l*sin(step)+p.getZ1());
      p.setRear(&p,dir,slope);
      //display
    }
  }

  static bool isLanded(position p)
  {
    return true;
  };


  static void fly(position * p, float slope, float dir)
  {
    p->setY1(p->getY1()-0.01);
    p->setRear(p,dir, slope);
  }


};

/***********************************************************************/
/*class vehicule{


  
};
*/








#endif

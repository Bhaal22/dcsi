/**-----------------------------------------------------------------------------
 * Release - KallistiOS 1.2.0
 *
 * Main.cpp : mainloop for the gamedi
 *
 *
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 *
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/

#include "Main.h"
#include "Init.h"
#include "assets/PalmTree.h"
#include "Landscape.h"
#include "assets/SkyBox.h"
#include "assets/StartPane.h"
#include "assets/TheLittleHouseOnThePrairie.h"
#include "assets/OisisVehicle.h"
#include "assets/NoelVehicle.h"
#include "Vehicle.h"
#include "move.hpp"
#include "io/ogg.h"
#include "io/wav.h"
#include "assets/MomoVehicle.h"
#include "assets/Caisse.h"

GLfloat xrot; /* X Rotation */
GLfloat yrot; /* Y Rotation */
GLfloat zrot; /* Z Rotation */
float z = 0.0f;
float x = 0.0f;
float y = 0.0f;
float rx = 0.0f;
float ry = 0.0f;

#define ROT_ANGLE 0.1

extern uint8 romdisk[];
KOS_INIT_ROMDISK(romdisk);

void CameraIntro(const Vector3D &camPos, float rotRatio, Camera *cam, Vehicle *vehi)
{

    Vector3D vehiPos = vehi->getPosition();
    cam->changePosition(camPos.x, camPos.y, camPos.z, vehiPos.x, vehiPos.y, vehiPos.z, 0, 1, 0);

    for (int i = 0; i < MATH_PI * 2; i += (rotRatio * ROTATION_ANGLE))
        cam->rotateAroundView(rotRatio);
}

bool DCSI::Init(int perso)
{
    /*cont_cond_t cond;
  	uint8	c;*/

    maple_device_t *cont;
    cont_state_t *state;
    Vehicle *vehicle;

    int i;
    int f = NEG;
    int ft = f;
    int throttle = 0;
    int brake = 0;

    ogg sultan("/rd/sons/ogg/sultanTribes.ogg");

    init();

    //speed tabulation
    for (i = -NEG; i < 0; i++)
        aSpeed[i + NEG] = -(0.24 * (float)7 * i / (PLUS + NEG) + 2) * log((float)-10 * (float)7 * i / (PLUS + NEG) + 1) * 3.6;
    for (i = NEG; i < PLUS + NEG; i++)
        aSpeed[i] = (-0.11 * (float)(7 * (i - NEG)) / (PLUS + NEG) + 2) * 5 * log((float)3 * (float)7 * (i - NEG) / (PLUS + NEG) + 1) * 3.6;

    /* Declaration des objets */
    SkyBox *skyBox = new SkyBox(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Landscape *cliff = new Landscape(JPEG, "/rd/terrain.jpg", "/rd/terrain.pcx", 256.0f, 32, 1, 1, 0);
    Landscape *sand = new Landscape(JPEG, "/rd/circuit.jpg", "/rd/circuit.pcx", 450.0f, 30, 4, 1 / 3.0f, -12.0f);
    PalmTree *palmier = new PalmTree("/rd/palmier.png", 69.0f, (sand->getYFromXZ(69, 12)) + 10, 12.0f, 20.0f, 20.0f, 20.0f);
    PalmTree *cactus = new PalmTree("/rd/cactus.png", 10.0f, sand->getYFromXZ(10, 30) + 10, 30.0f, 40.0f, 40.0f, 40.0f);
    Landscape *sea = new Landscape(NJPEG, NULL, "/rd/eau.pcx", 700.0f, 7, 4, 0.0f, 3.0f, 0.5f, 0.6f, 0.8f);
    TheLittleHouseOnThePrairie *house = new TheLittleHouseOnThePrairie(-170.0f, 4.5f, -140.0f, 4.0f, 4.0f, 4.0f);
    StartPane *startPane = new StartPane(-155.0f, sand->getYFromXZ(69, 12), 35.0f, 25.0f, 50.0f, 50.0f);
    Caisse *caisse1 = new Caisse("/rd/decor/caisses/caisseGrande.png", -320.0f, -5.0f, -280.0f, 15.0f, 15.0f, 15.0f);
    Caisse *caisse2 = new Caisse("/rd/decor/caisses/caisseCroix.png", 80.0f, 2.0f, -280.0f, 15.0f, 15.0f, 15.0f);
    /*Caisse *caisse3 = new Caisse("/cd/decor/caisses/explosif.png", 280.0f,  2.0f, -220.0f, 15.0f, 15.0f, 15.0f);*/

    /* Character creation */
    switch (perso + 2)
    {
    case 2:
        vehicle = new OisisVehicle(-155.0f, (sand->getYFromXZ(-155, 35)) + 1.25, 35.0f,
                                   -155.0f, (sand->getYFromXZ(-155, 34.9)) + 1.25, 34.9f,
                                   6.25f, 2.5f, 2.5f,
                                   1.5);
        break;

    case 3:
        vehicle = new MomoVehicle(-155.0f, sand->getYFromXZ(-155, 35) + 1.25, 35.0f,
                                  -155.0f, sand->getYFromXZ(-155, 34.9) + 1.25 - 0.5, 34.9f,
                                  2.5f, 5.0f, 2.5f,
                                  0.5);
        break;

    case 4:
        vehicle = new NoelVehicle(-155.0f, sand->getYFromXZ(-155, 35) + 7.5, 35.0f,
                                  -155.0f, sand->getYFromXZ(-155, 34.9) + 7.5 - 10, 34.9f,
                                  3.25f, 15.0f, 13.0f,
                                  10);
        break;

    default:
        vehicle = new NoelVehicle(-155.0f, sand->getYFromXZ(-155, 35) + 7.5, 35.0f,
                                  -155.0f, sand->getYFromXZ(-155, 34.9) + 7.5, 34.9f,
                                  3.25f, 15.0f, 13.0f,
                                  10);
        break;
    }

    sultan.play(1);
    //vehicle->updateSlope(sand);
    //Vector3D tmp1= (vehicle->getPosition()) + (Vector3D (0, 10,17.5));
    /*Vector3D tmp1= (vehicle->getPosition()) + (Vector3D (0,  10 - vehicle->getOffset(), 17.5));
	Vector3D tmp2= Vector3D (0,1,0);
	Camera cam(tmp1, vehicle->getPosition(), tmp2);*/

    Vector3D tmp1 = (vehicle->getPosition()) + (Vector3D(0, 10 - vehicle->getOffset(), 17.5));
    Vector3D tmp3 = Vector3D(0, 1, 0);
    Vector3D tmp2 = vehicle->getPosition();
    tmp2.y -= vehicle->getOffset();
    Camera cam(tmp1, tmp2, tmp3);

    palmier->shape();
    cactus->setColor(0.0f, 0.6f, 0.2f);
    cactus->shape();
    cliff->shape();
    sand->shape();
    sea->shape();
    startPane->shape();
    house->shape();
    vehicle->shape();
    caisse1->shape();
    caisse2->shape();
    /*caisse3->shape();*/

    //c = maple_first_controller();
    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
    bool noRotatingThisFrame = false;

    while (1)
    {
        noRotatingThisFrame = false;

        //c = maple_first_controller();
        cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

        ft = f;
        if (cont == nullptr)
            continue;

        state = (cont_state_t *)maple_dev_status(cont);
        //if (cont_get_cond(c, &cond) < 0)
        if (!state)
            continue;

        //if (!(cond.buttons & CONT_START)) {
        if (!(state->buttons & CONT_START))
            sultan.stop();
        return false;
    }

    //if (!(cond.buttons & CONT_DPAD_LEFT)){
    if (!(state->buttons & CONT_DPAD_LEFT))
    {
        if (f != NEG)
        {
            vehicle->rotate(ROT_ANGLE, sand);
            cam.move(vehicle->getPosition(), vehicle->getDirection());
        }
    }
    //if (!(cond.buttons & CONT_DPAD_RIGHT)) {
    if (!(state->buttons & CONT_DPAD_RIGHT))
    {
        if (f != NEG)
        {
            vehicle->rotate(-ROT_ANGLE, sand);
            cam.move(vehicle->getPosition(), vehicle->getDirection());
        }
    }

    brake = 0;
    //if (!(cond.buttons & CONT_B))
    if (!(state->buttons & CONT_B))
    {
        brake = 1;
        throttle = 0;
        //if (!(cond.buttons & CONT_A))
        if (!(state->buttons & CONT_A))
            throttle = 1;
        //if (!(cond.buttons & CONT_B )&&!(cond.buttons & CONT_X ))
        if (!(state->buttons & CONT_B) && !(state->buttons & CONT_X))
            screenShot();

        //if (!(cond.buttons & CONT_Y)) {
        if (!(state->buttons & CONT_Y))
        {
            wav klaxon("/rd/Klaxon.wav");
            klaxon.play();
        }
        //if (cond.ltrig) {
        if (state->ltrig)
        {
            noRotatingThisFrame = true;
            cam.rotateAroundView(2);
        }
        //if (cond.rtrig) {
        if (state->rtrig)
        {
            noRotatingThisFrame = true;
            cam.rotateAroundView(-2);
        }

        //if (!(cond.buttons & CONT_B)&&!(cond.buttons & CONT_X)&&!(cond.buttons & CONT_A)&&!(cond.buttons & CONT_Y)) {
        if (!(state->buttons & CONT_B) && !(state->buttons & CONT_X) && !(state->buttons & CONT_A) && !(state->buttons & CONT_Y))
        {
            return false;
        }

        /* Begin frame */

        /* Draw the GL "scene" */

        Vector3D dir = vehicle->getDirection();
        Vector3D dirNoY(dir.x, 0, dir.z);
        if (!noRotatingThisFrame)
            cam.updateRotation(vehicle->getPosition(), dirNoY);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glKosBeginFrame();

        /* Switch to the blended polygon list if needed */
        glKosFinishList();
        glDepthMask(0);
        /*******************************************/

        glLoadIdentity();
        glPushMatrix();
        cam.render();
        glEnable(GL_KOS_NEARZ_CLIPPING);
        glPushMatrix();
        glScalef(350.0f, 200.0f, 350.0f);
        /* Paint the Sky Box */
        skyBox->shape();
        glPopMatrix();
        cliff->displayElement();
        sea->displayElement();
        glPushMatrix();
        glScalef(2.0f, 2.0f, 2.0f);
        house->displayElement();
        glPopMatrix();
        palmier->displayElement();
        cactus->displayElement();

        /* Draw the second house on the Prairie */
        glPushMatrix();
        glTranslatef(200.0f, 60.0f, 200.0f);
        house->displayElement();
        glPopMatrix();

        /* Draw a second cactus */
        glPushMatrix();
        glTranslatef(-320.0f, sand->getYFromXZ(120, 250), -120.0f);
        cactus->displayElement();
        glPopMatrix();

        /* Draw a second palmtree */
        glPushMatrix();
        glTranslatef(-125.0f, sand->getYFromXZ(-125, 10), 10.0f);
        cactus->displayElement();
        glPopMatrix();

        sand->displayElement();
        startPane->displayElement();
        caisse1->displayElement();
        caisse2->displayElement();
        /*caisse3->displayElement();*/

        /* Draw the vehicle */
        glPushMatrix();

        /* METTRE LA PENTE A LA PLACE DU PREMIER 0 */
        f = PhysicalEngine::speed(f, throttle, brake, 0, 0);
        float d = PhysicalEngine::distance(ft, f) * SCALE;

        vehicle->moveRelatif(d, sand);
        cam.move(vehicle->getPosition(), vehicle->getDirection());

        glTranslatef(vehicle->getPosition().x, vehicle->getPosition().y, vehicle->getPosition().z);

        //1st rotation, in x and z
        float rotatefAngle = angleBetweenVectorsWithReference(Vector3D(0, 0, 1), Vector3D(1, 0, 0), dirNoY);
        //convert to degrees :
        rotatefAngle = radToDeg(rotatefAngle);
        Vector3D rotateUp = cam.getUpVector();
        glRotatef(rotatefAngle, rotateUp.x, rotateUp.y, rotateUp.z);

        //2nd rotation, in z and y
        Vector3D tF = vehicle->getFront();
        Vector3D tPos = vehicle->getPosition();
        Vector3D dir2 = tF - tPos;
        rotatefAngle = asin(dir2.y / dir2.Magnitude());
        //convert to degrees :
        rotatefAngle = radToDeg(rotatefAngle);
        Vector3D rotateX(1, 0, 0);
        glRotatef(-rotatefAngle, rotateX.x, rotateX.y, rotateX.z);

        vehicle->displayElement();
        glPopMatrix();
        glDisable(GL_KOS_NEARZ_CLIPPING);
        glPopMatrix();

        /* Finish the frame */
        glKosFinishFrame();
    }
}

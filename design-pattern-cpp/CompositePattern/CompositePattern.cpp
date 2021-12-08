// CompositePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Weapon.h"

int _tmain(int argc, _TCHAR* argv[])
{
    IWeapon* rootClip = new Clip();

    IWeapon* childClip = new Clip();
    childClip->add(new TraceBullet());
    childClip->add(new TraceBullet());
    childClip->add(new TraceBullet());

    rootClip->add(new LineBullet());
    rootClip->add(childClip);
    rootClip->add(new LineBullet());

    rootClip->fire();

    delete childClip;
    delete rootClip;

	return 0;
}


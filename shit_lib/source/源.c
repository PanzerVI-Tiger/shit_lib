#pragma warning(disable: 6011)

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tagA A;

typedef struct tagVTableA {
	void(*const f)(A* self);
} VTableA;

typedef struct tagPubA {
	int x;
} PubA;

struct tagA {
	PubA		   pub;
	VTableA const* vt;
};

void fA(A* self) 
{
	printf("A: self = { x: %d }\n", self->pub.x);
}

VTableA const vtableA = {
	.f = &fA,
};

void initialA(A* self, int x)
{
	self->pub.x = x;
	self->vt = &vtableA;
}

typedef struct tagB B;

typedef struct tagVTableB {
	VTableA;
	void(*const g)(B* self, int x, int y);
} VTableB;

typedef struct tagPubB {
	PubA;
	int y;
} PubB;

struct tagB {
	PubB	       pub;
	VTableB const* vt;
};

void fB(B* self) 
{
	printf("B: self = { x: %d, y: %d }\n", self->pub.x, self->pub.y);
}

void gB(B* self, int x, int y)
{
	self->pub.x = x;
	self->pub.y = y;
}

VTableB const vtableB = {
	.f = &fB,
	.g = &gB,
};

void initialB(B* self, int x, int y)
{
	self->pub.x = x;
	self->pub.y = y;
	self->vt = (VTableB*)&vtableB;
}


int maina()
{
	A a;
	initialA(&a, 1);
	a.vt->f(&a);
	
	B b;
	initialB(&b, 2, 3);
	b.vt->f(&b);
	b.vt->g(&b, 4, 5);
	b.vt->f(&b);
	
	A* pb = malloc(sizeof(B));
	initialB(pb, 6, 7);
	pb->vt->f(pb);
	free(pb);
	union X {
		char* i;
		double j;
	} x = { 1 };

	return 0;
}
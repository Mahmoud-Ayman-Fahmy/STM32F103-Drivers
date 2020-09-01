/*******************************************/
/* Author     : Mahmoud Ayman              */
/* Date       : 28 AUG 2020                */
/* Version    : V01                        */
/* File Name  : AFIO_private               */
/*******************************************/

#ifndef  AFIO_PRIVATE_H
#define  AFIO_PRIVATE_H

typedef struct {
		u32 EVCR;
		u32 MAPR;
		u32 EXTICR[4];
		u32 MAPR2;
}AFIO_t;

#define AFIO ((volatile AFIO_t*)0x40010000)

#endif
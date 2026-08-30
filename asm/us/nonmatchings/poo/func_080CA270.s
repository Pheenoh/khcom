.syntax unified
	.align 2, 0
	.global func_080CA270
	.thumb
	.thumb_func
	.type func_080CA270, %function
func_080CA270: @ 080CA270
	push {r4, r5, r6, lr}
	bl func_0802F208
	ldr r0, _080CA334 @ =0x0203C3FC
	ldr r1, [r0, #0x00]
	ldr r0, _080CA338 @ =0xFFFF8800
	adds r4, r1, r0
	ldr r0, _080CA33C @ =0x0203C408
	ldr r0, [r0, #0x00]
	ldr r2, _080CA340 @ =0xFFFFB000
	adds r3, r0, r2
	cmp r3, #0x00
	bge _080CA28C
	movs r3, #0x00
_080CA28C:
	movs r0, #0xF0
	lsls r0, r0, #0x07
	adds r1, r1, r0
	ldr r0, _080CA344 @ =0x000EDF00
	cmp r1, r0
	ble _080CA29A
	ldr r4, _080CA348 @ =0x000DEF00
_080CA29A:
	movs r2, #0xA0
	lsls r2, r2, #0x08
	adds r1, r3, r2
	movs r0, #0x83
	lsls r0, r0, #0x0C
	cmp r1, r0
	ble _080CA2AC
	movs r3, #0xF2
	lsls r3, r3, #0x0B
_080CA2AC:
	ldr r2, _080CA34C @ =0x0203C40C
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x08
	subs r0, r4, r0
	asrs r4, r0, #0x03
	ldr r1, _080CA350 @ =0x0203C3F8
	ldrh r0, [r1, #0x00]
	lsls r0, r0, #0x08
	subs r0, r3, r0
	asrs r3, r0, #0x03
	movs r0, #0xC0
	lsls r0, r0, #0x02
	adds r6, r2, #0x0
	adds r5, r1, #0x0
	cmp r4, r0
	bgt _080CA2D2
	ldr r0, _080CA354 @ =0xFFFFFD00
	cmp r4, r0
	bge _080CA2D4
_080CA2D2:
	adds r4, r0, #0x0
_080CA2D4:
	movs r0, #0xC0
	lsls r0, r0, #0x02
	cmp r3, r0
	bgt _080CA2E2
	ldr r0, _080CA354 @ =0xFFFFFD00
	cmp r3, r0
	bge _080CA2E4
_080CA2E2:
	adds r3, r0, #0x0
_080CA2E4:
	adds r0, r4, #0x0
	cmp r4, #0x00
	bge _080CA2EC
	negs r0, r4
_080CA2EC:
	cmp r0, #0x32
	bgt _080CA2F2
	movs r4, #0x00
_080CA2F2:
	adds r0, r3, #0x0
	cmp r3, #0x00
	bge _080CA2FA
	negs r0, r3
_080CA2FA:
	cmp r0, #0x32
	bgt _080CA300
	movs r3, #0x00
_080CA300:
	asrs r0, r4, #0x08
	ldrh r1, [r6, #0x00]
	adds r0, r0, r1
	strh r0, [r6, #0x00]
	asrs r0, r3, #0x08
	ldrh r2, [r5, #0x00]
	adds r0, r0, r2
	strh r0, [r5, #0x00]
	bl func_0802F268
	asrs r0, r0, #0x08
	ldrh r1, [r5, #0x00]
	adds r0, r0, r1
	strh r0, [r5, #0x00]
	ldr r0, _080CA358 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldrh r0, [r5, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CA334: .4byte 0x0203C3FC
_080CA338: .4byte 0xFFFF8800
_080CA33C: .4byte 0x0203C408
_080CA340: .4byte 0xFFFFB000
_080CA344: .4byte 0x000EDF00
_080CA348: .4byte 0x000DEF00
_080CA34C: .4byte 0x0203C40C
_080CA350: .4byte 0x0203C3F8
_080CA354: .4byte 0xFFFFFD00
_080CA358: .4byte 0x02039BA0
.syntax divided

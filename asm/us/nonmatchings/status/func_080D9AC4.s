.syntax unified
	.align 2, 0
	.global func_080D9AC4
	.thumb
	.thumb_func
	.type func_080D9AC4, %function
func_080D9AC4: @ 080D9AC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r6, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0x80
	subs r0, r0, r2
	lsls r1, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r1
	bge _080D9AE4
	str r1, [r4, #0x00]
	movs r6, #0x01
_080D9AE4:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r2, r1
	lsls r2, r0, #0x08
	ldr r0, [r4, #0x00]
	cmp r0, r2
	ble _080D9AF6
	str r2, [r4, #0x00]
	movs r6, #0x01
_080D9AF6:
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	movs r0, #0x90
	lsls r0, r0, #0x02
	subs r0, r0, r3
	lsls r2, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r2
	bge _080D9B0C
	str r2, [r5, #0x00]
	movs r6, #0x01
_080D9B0C:
	movs r1, #0x9E
	lsls r1, r1, #0x02
	adds r0, r3, r1
	lsls r3, r0, #0x08
	ldr r0, [r5, #0x00]
	cmp r0, r3
	ble _080D9B1E
	str r3, [r5, #0x00]
	movs r6, #0x01
_080D9B1E:
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

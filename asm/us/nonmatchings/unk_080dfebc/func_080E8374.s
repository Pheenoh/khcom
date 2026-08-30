.syntax unified
	.align 2, 0
	.global func_080E8374
	.thumb
	.thumb_func
	.type func_080E8374, %function
func_080E8374: @ 080E8374
	push {r4, r5, lr}
	adds r2, r0, #0x0
	ldr r0, _080E83B8 @ =0x02039BA0
	ldr r3, [r0, #0x00]
	ldr r1, [r3, #0x1C]
	ldr r0, [r3, #0x20]
	adds r1, r1, r0
	movs r4, #0x1A
	ldsh r0, [r2, r4]
	lsls r0, r0, #0x08
	movs r5, #0x80
	lsls r5, r5, #0x07
	adds r0, r0, r5
	adds r4, r1, r0
	ldr r1, [r2, #0x00]
	ldr r0, [r3, #0x00]
	cmp r1, r0
	blt _080E83B2
	movs r5, #0xF0
	lsls r5, r5, #0x08
	adds r0, r0, r5
	cmp r1, r0
	bgt _080E83B2
	ldr r0, [r2, #0x04]
	ldr r1, [r2, #0x08]
	adds r1, r0, r1
	ldr r0, [r3, #0x04]
	cmp r1, r0
	blt _080E83B2
	cmp r1, r4
	ble _080E83BC
_080E83B2:
	movs r0, #0x01
	b _080E83BE
	.byte 0x00, 0x00
_080E83B8: .4byte 0x02039BA0
_080E83BC:
	movs r0, #0x00
_080E83BE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x04, 0x48, 0x01, 0x88, 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x40, 0x1A, 0x00, 0x04, 0x00, 0x0C
	.byte 0x70, 0x47, 0x00, 0x00, 0x7A, 0x4F, 0x03, 0x02
.syntax divided

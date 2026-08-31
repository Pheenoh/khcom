.syntax unified
	.align 2, 0
	.global func_080DB468
	.thumb
	.thumb_func
	.type func_080DB468, %function
func_080DB468: @ 080DB468
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	bl GetRandom
	lsls r0, r0, #0x10
	movs r1, #0xF0
	lsls r1, r1, #0x0C
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #0x07
	bls _080DB4C4
	ldr r0, _080DB4B8 @ =0x0203C578
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _080DB4BC @ =0xFFFFC000
	str r0, [sp, #0x000]
	movs r4, #0x00
	adds r5, r6, #0x0
	adds r5, #0x08
_080DB490:
	adds r0, r5, #0x0
	ldr r1, _080DB4C0 @ =0x09EF50B8
	mov r2, sp
	bl TaskCreate
	lsls r2, r4, #0x02
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r1, r6, r3
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x000]
	movs r1, #0xD0
	lsls r1, r1, #0x07
	adds r0, r0, r1
	str r0, [sp, #0x000]
	adds r4, #0x01
	cmp r4, #0x04
	ble _080DB490
	b _080DB4FA
_080DB4B8: .4byte 0x0203C578
_080DB4BC: .4byte 0xFFFFC000
_080DB4C0: .4byte 0x09EF50B8
_080DB4C4:
	ldr r0, _080DB504 @ =0x0203C578
	movs r1, #0x00
	strb r1, [r0, #0x00]
	movs r0, #0x8C
	lsls r0, r0, #0x0A
	str r0, [sp, #0x000]
	movs r4, #0x00
	adds r5, r6, #0x0
	adds r5, #0x08
_080DB4D6:
	adds r0, r5, #0x0
	ldr r1, _080DB508 @ =0x09EF50B8
	mov r2, sp
	bl TaskCreate
	lsls r2, r4, #0x02
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r1, r6, r3
	adds r1, r1, r2
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x000]
	ldr r1, _080DB50C @ =0xFFFF9800
	adds r0, r0, r1
	str r0, [sp, #0x000]
	adds r4, #0x01
	cmp r4, #0x04
	ble _080DB4D6
_080DB4FA:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DB504: .4byte 0x0203C578
_080DB508: .4byte 0x09EF50B8
_080DB50C: .4byte 0xFFFF9800
.syntax divided

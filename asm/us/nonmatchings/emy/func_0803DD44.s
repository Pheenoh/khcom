.syntax unified
	.align 2, 0
	.global func_0803DD44
	.thumb
	.thumb_func
	.type func_0803DD44, %function
func_0803DD44: @ 0803DD44
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r6, #0x3C
	add r2, sp, #0x004
	adds r0, r6, #0x0
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	ldr r0, _0803DD74 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x30
	lsls r0, r0, #0x08
	ldr r2, [sp, #0x000]
	cmp r2, r0
	bge _0803DD78
	adds r2, #0x28
	b _0803DDC4
_0803DD74: .4byte 0x02039B84
_0803DD78:
	adds r0, r1, #0x0
	adds r0, #0xDC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x30
	lsls r0, r0, #0x08
	cmp r2, r0
	ble _0803DD8C
	subs r2, #0x28
	b _0803DDC4
_0803DD8C:
	bl GetRandom
	movs r2, #0x85
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r2, #0x00
	ldsh r5, [r1, r2]
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	negs r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	adds r5, r5, r4
	lsls r5, r5, #0x08
	ldr r0, [r6, #0x04]
	ldr r1, [sp, #0x000]
	adds r2, r1, r5
	cmp r0, r1
	bge _0803DDC4
	subs r2, r1, r5
_0803DDC4:
	ldr r3, [sp, #0x004]
	ldr r0, [r6, #0x04]
	ldr r1, [r6, #0x08]
	bl GetAngle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

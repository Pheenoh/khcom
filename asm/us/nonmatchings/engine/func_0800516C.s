.syntax unified
	.align 2, 0
	.global func_0800516C
	.thumb
	.thumb_func
	.type func_0800516C, %function
func_0800516C: @ 0800516C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r7, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080051BC @ =0x03007500
	ldrh r1, [r0, #0x00]
	movs r0, #0x07
	ands r0, r1
	cmp r0, #0x00
	beq _0800518C
	subs r0, r4, #0x2
	cmp r0, #0x01
	bls _080051B6
_0800518C:
	adds r0, r4, #0x0
	bl func_08004FC8
	ldr r3, _080051C0 @ =0x030074D4
	ldr r1, [r3, #0x00]
	lsls r2, r4, #0x04
	adds r0, r1, #0x4
	adds r0, r0, r2
	str r7, [r0, #0x00]
	adds r1, r1, r2
	movs r4, #0x00
	strb r5, [r1, #0x08]
	ldr r0, [r3, #0x00]
	adds r0, r0, r2
	strb r6, [r0, #0x09]
	ldr r0, [r3, #0x00]
	adds r0, r0, r2
	strh r4, [r0, #0x0A]
	strh r4, [r0, #0x0C]
	movs r1, #0x01
	strb r1, [r0, #0x00]
_080051B6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080051BC: .4byte 0x03007500
_080051C0: .4byte 0x030074D4
.syntax divided

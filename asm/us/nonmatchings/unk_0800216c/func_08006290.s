.syntax unified
	.align 2, 0
	.global func_08006290
	.thumb
	.thumb_func
	.type func_08006290, %function
func_08006290: @ 08006290
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r0, _080062E8 @ =0x03007568
	ldr r3, [r0, #0x00]
	ldr r0, _080062EC @ =0x00000594
	adds r4, r3, r0
	ldrh r1, [r4, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080062B6
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080062E0
_080062B6:
	movs r2, #0x00
	movs r0, #0x01
	strh r0, [r4, #0x00]
	ldr r1, _080062F0 @ =0x0000058C
	adds r0, r3, r1
	strh r5, [r0, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x03
	adds r1, r3, r0
	lsls r0, r6, #0x08
	str r0, [r1, #0x00]
	movs r1, #0xB1
	lsls r1, r1, #0x03
	adds r0, r3, r1
	str r2, [r0, #0x00]
	subs r1, #0x04
	adds r0, r3, r1
	str r2, [r0, #0x00]
	adds r1, #0x0C
	adds r0, r3, r1
	str r7, [r0, #0x00]
_080062E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080062E8: .4byte 0x03007568
_080062EC: .4byte 0x00000594
_080062F0: .4byte 0x0000058C
.syntax divided

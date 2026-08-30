.syntax unified
	.align 2, 0
	.global func_08110058
	.thumb
	.thumb_func
	.type func_08110058, %function
func_08110058: @ 08110058
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r5, r2, #0x0
	adds r4, r3, #0x0
	cmp r4, #0x1F
	bgt _0811006A
	movs r0, #0x1F
	bics r0, r4
	b _0811006C
_0811006A:
	movs r0, #0x00
_0811006C:
	adds r4, r0, #0x0
	subs r5, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r5, r0
	beq _081100B8
	mov r12, r0
	lsls r0, r5, #0x01
	adds r7, r0, r6
	adds r6, r0, r1
_08110080:
	ldrh r3, [r6, #0x00]
	movs r1, #0x1F
	adds r0, r3, #0x0
	ands r0, r1
	adds r2, r0, #0x0
	muls r2, r4
	asrs r2, r2, #0x05
	ands r2, r1
	lsls r1, r1, #0x05
	adds r0, r3, #0x0
	ands r0, r1
	muls r0, r4
	asrs r0, r0, #0x05
	ands r0, r1
	orrs r2, r0
	lsls r1, r1, #0x05
	ands r3, r1
	adds r0, r3, #0x0
	muls r0, r4
	asrs r0, r0, #0x05
	ands r0, r1
	orrs r2, r0
	strh r2, [r7, #0x00]
	subs r7, #0x02
	subs r6, #0x02
	subs r5, #0x01
	cmp r5, r12
	bne _08110080
_081100B8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

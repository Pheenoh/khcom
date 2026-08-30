.syntax unified
	.align 2, 0
	.global func_08031F98
	.thumb
	.thumb_func
	.type func_08031F98, %function
func_08031F98: @ 08031F98
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _08031FC4 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _08031FFC
	cmp r0, #0x53
	bgt _08031FC8
	cmp r0, #0x2D
	beq _08031FE0
	cmp r0, #0x2D
	ble _0803201A
	cmp r0, #0x40
	beq _08031FEE
	b _0803201A
	.byte 0x00, 0x00
_08031FC4: .4byte 0x02039BA0
_08031FC8:
	cmp r0, #0xAD
	beq _0803200E
	cmp r0, #0xAD
	bgt _08031FD6
	cmp r0, #0x80
	beq _0803200A
	b _0803201A
_08031FD6:
	cmp r0, #0xC0
	beq _08032012
	cmp r0, #0xD3
	beq _08032016
	b _0803201A
_08031FE0:
	movs r3, #0x04
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_08031FEE:
	movs r3, #0x03
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_08031FFC:
	movs r3, #0x02
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_0803200A:
	movs r3, #0x01
	b _0803201C
_0803200E:
	movs r3, #0x02
	b _0803201C
_08032012:
	movs r3, #0x03
	b _0803201C
_08032016:
	movs r3, #0x04
	b _0803201C
_0803201A:
	movs r3, #0x00
_0803201C:
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	ldr r0, _08032068 @ =0x0000FFFD
	ands r0, r1
_08032026:
	strh r0, [r2, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xA8
	ldr r0, [r1, #0x00]
	cmp r0, r6
	bne _08032036
	movs r0, #0x04
	orrs r7, r0
_08032036:
	str r6, [r1, #0x00]
	lsls r4, r6, #0x02
	adds r4, r4, r6
	lsls r4, r4, #0x04
	lsls r0, r3, #0x04
	ldr r1, _0803206C @ =0x0813C89C
	adds r0, r0, r1
	adds r4, r4, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	ldrb r1, [r4, #0x0C]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	adds r2, r7, #0x0
	bl func_08005974
	ldr r0, [r5, #0x00]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08032068: .4byte 0x0000FFFD
_0803206C: .4byte 0x0813C89C
.syntax divided

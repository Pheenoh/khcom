.syntax unified
	.align 2, 0
	.global func_0800CD40
	.thumb
	.thumb_func
	.type func_0800CD40, %function
func_0800CD40: @ 0800CD40
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0x3C
	adds r0, r0, r4
	mov r12, r0
	ldr r5, _0800CD80 @ =0x02039BB0
	ldr r0, [r5, #0x08]
	movs r1, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0800CDBA
	mov r2, r12
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0800CD84 @ =0x00004002
	ldr r3, _0800CD88 @ =0x00000000
	orrs r0, r2
	mov r2, r12
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r1, #0xDC
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800CD8C
	movs r0, #0x2E
	ldsh r1, [r2, r0]
	movs r0, #0xCC
	muls r0, r1
	b _0800CD9A
	.byte 0x00, 0x00
_0800CD80: .4byte 0x02039BB0
_0800CD84: .4byte 0x00004002
_0800CD88: .4byte 0x00000000
_0800CD8C:
	mov r2, r12
	movs r0, #0x2E
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
_0800CD9A:
	asrs r0, r0, #0x08
	strh r0, [r2, #0x20]
	movs r0, #0x80
	lsls r0, r0, #0x02
	mov r1, r12
	str r0, [r1, #0x24]
	ldr r0, _0800CDE8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x76
	movs r1, #0x00
	strh r1, [r0, #0x00]
	mov r0, r12
	adds r0, #0xA8
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
_0800CDBA:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	adds r2, #0x04
	adds r0, r4, r2
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	mov r2, r12
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0800CDEC @ =0xFFFFFCFF
	ands r0, r2
	mov r2, r12
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	pop {r4, r5}
	pop {r0}
	bx r0
_0800CDE8: .4byte 0x02039B84
_0800CDEC: .4byte 0xFFFFFCFF
.syntax divided

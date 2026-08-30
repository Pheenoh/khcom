.syntax unified
	.align 2, 0
	.global func_08004FC8
	.thumb
	.thumb_func
	.type func_08004FC8, %function
func_08004FC8: @ 08004FC8
	cmp r0, #0x01
	beq _08004FE8
	cmp r0, #0x01
	bcc _08004FDA
	cmp r0, #0x02
	beq _08004FF8
	cmp r0, #0x03
	beq _08005008
	b _08005016
_08004FDA:
	ldr r0, _08004FE4 @ =0x03007500
	ldrh r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	b _08005010
_08004FE4: .4byte 0x03007500
_08004FE8:
	ldr r0, _08004FF4 @ =0x03007500
	ldrh r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x02
	b _08005010
	.byte 0x00, 0x00
_08004FF4: .4byte 0x03007500
_08004FF8:
	ldr r0, _08005004 @ =0x03007500
	ldrh r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x03
	b _08005010
	.byte 0x00, 0x00
_08005004: .4byte 0x03007500
_08005008:
	ldr r0, _08005018 @ =0x03007500
	ldrh r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x04
_08005010:
	adds r2, r3, #0x0
	orrs r1, r2
	strh r1, [r0, #0x00]
_08005016:
	bx lr
_08005018: .4byte 0x03007500
.syntax divided

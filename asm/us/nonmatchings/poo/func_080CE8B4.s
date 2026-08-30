.syntax unified
	.align 2, 0
	.global func_080CE8B4
	.thumb
	.thumb_func
	.type func_080CE8B4, %function
func_080CE8B4: @ 080CE8B4
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080CE880
	adds r1, r4, #0x0
	adds r1, #0xBA
	strh r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xB8
	ldrb r0, [r0, #0x00]
	cmp r0, #0xAD
	bne _080CE8E8
	ldr r1, _080CE8E4 @ =0x096FD5FC
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x28]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x2C]
	adds r2, r4, #0x0
	adds r2, #0xA8
	ldr r0, [r1, #0x08]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x0C]
	b _080CE93E
_080CE8E4: .4byte 0x096FD5FC
_080CE8E8:
	cmp r0, #0x53
	bne _080CE908
	ldr r1, _080CE904 @ =0x096FD5FC
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x28]
	ldr r0, [r1, #0x0C]
	str r0, [r4, #0x2C]
	adds r2, r4, #0x0
	adds r2, #0xA8
	ldr r0, [r1, #0x10]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x14]
	b _080CE93E
_080CE904: .4byte 0x096FD5FC
_080CE908:
	cmp r0, #0x2D
	bne _080CE928
	ldr r1, _080CE924 @ =0x096FD5FC
	ldr r0, [r1, #0x10]
	str r0, [r4, #0x28]
	ldr r0, [r1, #0x14]
	str r0, [r4, #0x2C]
	adds r2, r4, #0x0
	adds r2, #0xA8
	ldr r0, [r1, #0x18]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x1C]
	b _080CE93E
_080CE924: .4byte 0x096FD5FC
_080CE928:
	ldr r1, _080CE958 @ =0x096FD5FC
	ldr r0, [r1, #0x18]
	str r0, [r4, #0x28]
	ldr r0, [r1, #0x1C]
	str r0, [r4, #0x2C]
	adds r2, r4, #0x0
	adds r2, #0xA8
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x04]
_080CE93E:
	str r0, [r2, #0x00]
	ldr r0, _080CE95C @ =0xFFFFE800
	str r0, [r4, #0x30]
	adds r1, r4, #0x0
	adds r1, #0xBE
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r0, r4, #0x0
	bl func_080CE818
	pop {r4}
	pop {r0}
	bx r0
_080CE958: .4byte 0x096FD5FC
_080CE95C: .4byte 0xFFFFE800
.syntax divided

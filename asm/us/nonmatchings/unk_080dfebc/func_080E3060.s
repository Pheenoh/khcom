.syntax unified
	.align 2, 0
	.global func_080E3060
	.thumb
	.thumb_func
	.type func_080E3060, %function
func_080E3060: @ 080E3060
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, _080E3098 @ =0x02034F20
	ldr r2, [r1, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r2, r1, r2
	ldr r1, [r2, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _080E3092
	strh r5, [r2, #0x00]
	strh r4, [r2, #0x02]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x04
	str r0, [r2, #0x04]
_080E3092:
	pop {r4, r5}
	pop {r0}
	bx r0
_080E3098: .4byte 0x02034F20
.syntax divided

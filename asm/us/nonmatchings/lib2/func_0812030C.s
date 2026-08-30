.syntax unified
	.align 2, 0
	.global func_0812030C
	.thumb
	.thumb_func
	.type func_0812030C, %function
func_0812030C: @ 0812030C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_08120460
	ldr r0, _08120364 @ =0x03007FF0
	ldr r5, [r0, #0x00]
	movs r0, #0xF0
	lsls r0, r0, #0x0C
	ands r0, r4
	lsrs r4, r0, #0x10
	strb r4, [r5, #0x08]
	ldr r1, _08120368 @ =0x09D6D4BC
	subs r0, r4, #0x1
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r4, [r0, #0x00]
	str r4, [r5, #0x10]
	movs r0, #0xC6
	lsls r0, r0, #0x03
	adds r1, r4, #0x0
	bl func_0811D5EC
	strb r0, [r5, #0x0B]
	ldr r0, _0812036C @ =0x00091D1B
	muls r0, r4
	ldr r1, _08120370 @ =0x00001388
	adds r0, r0, r1
	ldr r1, _08120374 @ =0x00002710
	bl func_0811D5EC
	adds r1, r0, #0x0
	str r1, [r5, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl func_0811D5EC
	adds r0, #0x01
	asrs r0, r0, #0x01
	str r0, [r5, #0x18]
	bl func_081204E0
	pop {r4, r5}
	pop {r0}
	bx r0
_08120364: .4byte 0x03007FF0
_08120368: .4byte 0x09D6D4BC
_0812036C: .4byte 0x00091D1B
_08120370: .4byte 0x00001388
_08120374: .4byte 0x00002710
.syntax divided

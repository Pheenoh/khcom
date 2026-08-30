.syntax unified
	.align 2, 0
	.global func_08085B84
	.thumb
	.thumb_func
	.type func_08085B84, %function
func_08085B84: @ 08085B84
	lsls r0, r0, #0x10
	ldr r2, _08085BA0 @ =0x08F70AB0
	ldr r1, _08085BA4 @ =0x0203A080
	lsrs r0, r0, #0x0F
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	ldr r0, _08085BA8 @ =0x00000FFF
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r2
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	bx lr
_08085BA0: .4byte 0x08F70AB0
_08085BA4: .4byte 0x0203A080
_08085BA8: .4byte 0x00000FFF
.syntax divided

.syntax unified
	.align 2, 0
	.global MPlayFadeOut
	.thumb
	.thumb_func
	.type MPlayFadeOut, %function
MPlayFadeOut: @ 0811FDC8
	push {lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x34]
	ldr r0, _0811FDE8 @ =0x68736D53
	cmp r3, r0
	bne _0811FDE2
	strh r1, [r2, #0x26]
	strh r1, [r2, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	strh r0, [r2, #0x28]
_0811FDE2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0811FDE8: .4byte 0x68736D53
.syntax divided

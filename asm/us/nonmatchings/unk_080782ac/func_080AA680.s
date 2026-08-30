.syntax unified
	.align 2, 0
	.global func_080AA680
	.thumb
	.thumb_func
	.type func_080AA680, %function
func_080AA680: @ 080AA680
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080AA6C8 @ =0x000006CC
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	ldr r2, _080AA6CC @ =0x000004CC
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	lsls r0, r0, #0x05
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	bl func_080A993C
	movs r3, #0xDA
	lsls r3, r3, #0x03
	adds r1, r4, r3
	movs r3, #0x00
	ldsh r2, [r1, r3]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	ldr r2, _080AA6D0 @ =0x000006D2
	adds r4, r4, r2
	adds r0, r0, r1
	ldrh r4, [r4, #0x00]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080609AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080AA6D4
	pop {r4}
	pop {r0}
	bx r0
_080AA6C8: .4byte 0x000006CC
_080AA6CC: .4byte 0x000004CC
_080AA6D0: .4byte 0x000006D2
.syntax divided

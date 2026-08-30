.syntax unified
	.align 2, 0
	.global func_080A0944
	.thumb
	.thumb_func
	.type func_080A0944, %function
func_080A0944: @ 080A0944
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	strh r0, [r5, #0x02]
	strh r4, [r5, #0x04]
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided

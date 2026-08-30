.syntax unified
	.align 2, 0
	.global func_080C73A4
	.thumb
	.thumb_func
	.type func_080C73A4, %function
func_080C73A4: @ 080C73A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	adds r2, r4, #0x0
	bl func_08005778
	ldr r0, _080C73D4 @ =0x02034CF8
	lsls r4, r4, #0x0A
	lsls r5, r5, #0x05
	orrs r4, r5
	orrs r4, r6
	strh r4, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080C73D4: .4byte 0x02034CF8
.syntax divided

.syntax unified
	.align 2, 0
	.global func_0810D364
	.thumb
	.thumb_func
	.type func_0810D364, %function
func_0810D364: @ 0810D364
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r2, #0x00
	movs r4, #0x00
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r2, r0
	bge _0810D398
_0810D374:
	lsls r1, r4, #0x02
	movs r3, #0x81
	lsls r3, r3, #0x04
	adds r0, r5, r3
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl func_0811095C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r4, #0x01
	adds r0, r5, #0x0
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r4, r0
	blt _0810D374
_0810D398:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	negs r0, r1
	orrs r0, r1
	lsrs r0, r0, #0x1F
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided

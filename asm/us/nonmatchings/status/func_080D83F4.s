.syntax unified
	.align 2, 0
	.global func_080D83F4
	.thumb
	.thumb_func
	.type func_080D83F4, %function
func_080D83F4: @ 080D83F4
	push {r4, r5, r6, lr}
	ldr r4, _080D8468 @ =0x02034F04
	ldr r0, [r4, #0x00]
	ldr r1, _080D846C @ =0x000004AC
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r2, #0x07
	movs r5, #0x92
	lsls r5, r5, #0x03
	adds r6, r4, #0x0
	movs r3, #0x18
_080D840E:
	ldr r0, [r4, #0x00]
	lsls r1, r2, #0x02
	adds r0, r0, r5
	adds r1, r0, r1
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	subs r3, #0x04
	subs r2, #0x01
	cmp r2, #0x00
	bgt _080D840E
	ldr r2, [r6, #0x00]
	ldr r0, _080D8470 @ =0x000004C4
	adds r3, r2, r0
	ldrh r0, [r3, #0x00]
	subs r0, #0x01
	strh r0, [r3, #0x00]
	movs r1, #0x98
	lsls r1, r1, #0x03
	adds r0, r2, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldrh r3, [r3, #0x00]
	adds r0, r0, r3
	lsls r0, r0, #0x02
	adds r2, r2, r0
	ldr r0, [r2, #0x00]
	bl _080D85F8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080D85C0
	ldr r1, [r6, #0x00]
	movs r2, #0x92
	lsls r2, r2, #0x03
	adds r1, r1, r2
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D8468: .4byte 0x02034F04
_080D846C: .4byte 0x000004AC
_080D8470: .4byte 0x000004C4
.syntax divided

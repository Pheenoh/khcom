.syntax unified
	.align 2, 0
	.global func_080D8374
	.thumb
	.thumb_func
	.type func_080D8374, %function
func_080D8374: @ 080D8374
	push {r4, r5, r6, lr}
	ldr r5, _080D83E8 @ =0x02034F04
	ldr r0, [r5, #0x00]
	movs r4, #0x92
	lsls r4, r4, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r2, #0x00
	adds r6, r5, #0x0
	movs r3, #0x04
_080D838C:
	ldr r0, [r5, #0x00]
	lsls r1, r2, #0x02
	adds r0, r0, r4
	adds r1, r0, r1
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r3, #0x04
	adds r2, #0x01
	cmp r2, #0x06
	ble _080D838C
	ldr r3, [r6, #0x00]
	ldr r0, _080D83EC @ =0x000004C4
	adds r1, r3, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldrh r2, [r1, #0x00]
	adds r2, #0x07
	movs r1, #0x98
	lsls r1, r1, #0x03
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r3, r3, r0
	ldr r0, [r3, #0x00]
	bl _080D85F8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080D85C0
	ldr r1, [r6, #0x00]
	ldr r2, _080D83F0 @ =0x000004AC
	adds r1, r1, r2
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D83E8: .4byte 0x02034F04
_080D83EC: .4byte 0x000004C4
_080D83F0: .4byte 0x000004AC
.syntax divided

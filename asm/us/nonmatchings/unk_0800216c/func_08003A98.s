.syntax unified
	.align 2, 0
	.global func_08003A98
	.thumb
	.thumb_func
	.type func_08003A98, %function
func_08003A98: @ 08003A98
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r6, _08003ACC @ =0x030074C8
	ldr r0, [r6, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x05
	adds r0, r0, r1
	bl func_08000C8C
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08003AC6
	ldr r0, [r6, #0x00]
	ldr r1, _08003AD0 @ =0x00001810
	adds r0, r0, r1
	ldrh r2, [r0, #0x00]
	ldrh r0, [r4, #0x06]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r5, r0
	bgt _08003AEA
_08003AC6:
	movs r0, #0x01
	b _08003B16
	.byte 0x00, 0x00
_08003ACC: .4byte 0x030074C8
_08003AD0: .4byte 0x00001810
_08003AD4:
	cmp r3, #0x00
	beq _08003ADA
	ldrh r0, [r3, #0x06]
_08003ADA:
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r5, r0
	ble _08003AC6
	adds r4, r3, #0x0
_08003AEA:
	cmp r4, #0x00
	beq _08003B14
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08000CD4
	adds r3, r0, #0x0
	ldrh r1, [r4, #0x08]
	ldrh r4, [r4, #0x06]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	adds r1, r1, r5
	ldr r0, _08003B1C @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r4, _08003B20 @ =0x00001812
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	ble _08003AD4
_08003B14:
	movs r0, #0x00
_08003B16:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08003B1C: .4byte 0x030074C8
_08003B20: .4byte 0x00001812
.syntax divided

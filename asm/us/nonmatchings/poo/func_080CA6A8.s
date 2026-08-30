.syntax unified
	.align 2, 0
	.global func_080CA6A8
	.thumb
	.thumb_func
	.type func_080CA6A8, %function
func_080CA6A8: @ 080CA6A8
	push {r4, r5, lr}
	ldr r3, _080CA70C @ =0x0203C3FC
	ldr r2, [r3, #0x00]
	adds r2, r2, r0
	str r2, [r3, #0x00]
	ldr r3, _080CA710 @ =0x0203C408
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r1, _080CA714 @ =0x02034DE4
	ldr r1, [r1, #0x00]
	cmp r1, r0
	bge _080CA6C4
	str r1, [r3, #0x00]
_080CA6C4:
	ldr r5, _080CA718 @ =0x0203C40C
	asrs r0, r2, #0x08
	subs r0, #0x78
	strh r0, [r5, #0x00]
	ldr r4, _080CA71C @ =0x0203C3F8
	ldr r0, [r3, #0x00]
	asrs r0, r0, #0x08
	subs r0, #0x50
	strh r0, [r4, #0x00]
	ldr r0, _080CA720 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldrh r0, [r5, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldrh r1, [r5, #0x00]
	ldrh r2, [r4, #0x00]
	movs r0, #0x03
	bl func_08005244
	ldrh r1, [r5, #0x00]
	ldrh r2, [r4, #0x00]
	movs r0, #0x01
	bl func_08005244
	ldrh r1, [r5, #0x00]
	ldrh r2, [r4, #0x00]
	movs r0, #0x02
	bl func_08005244
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CA70C: .4byte 0x0203C3FC
_080CA710: .4byte 0x0203C408
_080CA714: .4byte 0x02034DE4
_080CA718: .4byte 0x0203C40C
_080CA71C: .4byte 0x0203C3F8
_080CA720: .4byte 0x02039BA0
.syntax divided

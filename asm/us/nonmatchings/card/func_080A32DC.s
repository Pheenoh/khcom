.syntax unified
	.align 2, 0
	.global func_080A32DC
	.thumb
	.thumb_func
	.type func_080A32DC, %function
func_080A32DC: @ 080A32DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	movs r4, #0x00
	ldr r6, _080A3354 @ =0x0203A8C0
	adds r2, r5, #0x1
	ldr r3, _080A3358 @ =0x0000010D
_080A32E8:
	adds r1, r4, r6
	adds r0, r2, r4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r3
	bls _080A32E8
	movs r4, #0x00
	ldr r6, _080A335C @ =0x0203A080
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldr r3, _080A3360 @ =0x000003E6
_080A3306:
	lsls r0, r4, #0x01
	adds r1, r0, r6
	adds r0, r2, r0
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r3
	bls _080A3306
	movs r4, #0x00
	ldr r6, _080A3364 @ =0x02039DE0
_080A331E:
	lsls r1, r4, #0x03
	subs r1, r1, r4
	lsls r1, r1, #0x05
	adds r0, r1, r6
	adds r1, r5, r1
	movs r2, #0x8E
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r2, #0xE0
	bl memcpy
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x02
	bls _080A331E
	ldr r1, _080A3368 @ =0x0203A858
	ldr r2, _080A336C @ =0x000008DE
	adds r0, r5, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldrb r0, [r5, #0x00]
	bl SetActiveDeckIndex
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080A3354: .4byte 0x0203A8C0
_080A3358: .4byte 0x0000010D
_080A335C: .4byte 0x0203A080
_080A3360: .4byte 0x000003E6
_080A3364: .4byte 0x02039DE0
_080A3368: .4byte 0x0203A858
_080A336C: .4byte 0x000008DE
.syntax divided

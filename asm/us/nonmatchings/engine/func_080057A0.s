.syntax unified
	.align 2, 0
	.global func_080057A0
	.thumb
	.thumb_func
	.type func_080057A0, %function
func_080057A0: @ 080057A0
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r0, #0x01
	beq _080057D4
	cmp r0, #0x01
	bcc _080057C4
	cmp r0, #0x02
	beq _080057E4
	ldr r1, _080057BC @ =0x03007554
	ldr r3, _080057C0 @ =0x00001708
	b _080057E8
_080057BC: .4byte 0x03007554
_080057C0: .4byte 0x00001708
_080057C4:
	ldr r1, _080057CC @ =0x03007554
	ldr r3, _080057D0 @ =0x00001E01
	b _080057E8
	.byte 0x00, 0x00
_080057CC: .4byte 0x03007554
_080057D0: .4byte 0x00001E01
_080057D4:
	ldr r1, _080057DC @ =0x03007554
	ldr r3, _080057E0 @ =0x00001D02
	b _080057E8
	.byte 0x00, 0x00
_080057DC: .4byte 0x03007554
_080057E0: .4byte 0x00001D02
_080057E4:
	ldr r1, _08005804 @ =0x03007554
	ldr r3, _08005808 @ =0x00001B04
_080057E8:
	adds r0, r3, #0x0
	strh r0, [r1, #0x00]
	adds r3, r1, #0x0
	ldrh r0, [r3, #0x00]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3, #0x00]
	ldr r1, _0800580C @ =0x03007564
	lsls r0, r4, #0x08
	orrs r0, r2
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08005804: .4byte 0x03007554
_08005808: .4byte 0x00001B04
_0800580C: .4byte 0x03007564
.syntax divided

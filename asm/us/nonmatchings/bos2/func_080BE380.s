.syntax unified
	.align 2, 0
	.global func_080BE380
	.thumb
	.thumb_func
	.type func_080BE380, %function
func_080BE380: @ 080BE380
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl func_080BE3DC
	ldr r0, _080BE3D4 @ =0x0203B500
	ldr r1, [r0, #0x00]
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r0, _080BE3D8 @ =0x09EF28D0
	lsls r4, r4, #0x02
	adds r4, r4, r0
	ldr r1, [r4, #0x00]
	lsls r5, r5, #0x15
	lsrs r5, r5, #0x10
	movs r0, #0x01
	adds r2, r5, #0x0
	bl func_080050B8
	ldr r1, [r6, #0x00]
	movs r0, #0x93
	lsls r0, r0, #0x02
	adds r1, r1, r0
	ldrh r2, [r1, #0x00]
	movs r0, #0x11
	negs r0, r0
	ands r0, r2
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BE3D4: .4byte 0x0203B500
_080BE3D8: .4byte 0x09EF28D0
.syntax divided

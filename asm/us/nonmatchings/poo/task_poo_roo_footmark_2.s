.syntax unified
	.align 2, 0
	.global task_poo_roo_footmark_2
	.thumb
	.thumb_func
	.type task_poo_roo_footmark_2, %function
task_poo_roo_footmark_2: @ 080CF198
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, [r4, #0x0C]
	asrs r0, r0, #0x08
	ldr r1, _080CF1EC @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r4, #0x10]
	asrs r1, r1, #0x08
	ldr r2, _080CF1F0 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0x00
	str r5, [sp, #0x000]
	movs r2, #0x30
	str r2, [sp, #0x004]
	movs r2, #0x00
	movs r3, #0x30
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF1F4
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CF24C
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_080CCBD4
	str r5, [r4, #0x04]
	b _080CF24C
	.byte 0x00, 0x00
_080CF1EC: .4byte 0x0203C40C
_080CF1F0: .4byte 0x0203C3F8
_080CF1F4:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CF22A
	ldr r0, _080CF254 @ =0x09849D18
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x1C
	movs r1, #0x90
	lsls r1, r1, #0x02
	adds r2, r4, #0x0
	adds r2, #0x0C
	adds r0, r5, #0x0
	bl func_080CCB90
	movs r0, #0x05
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF22A
	adds r0, r5, #0x0
	movs r1, #0x00
	bl func_080CCB84
_080CF22A:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080CF258 @ =0x0000FFF1
	str r4, [sp, #0x00C]
	bl DrawSprite
_080CF24C:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CF254: .4byte 0x09849D18
_080CF258: .4byte 0x0000FFF1
.syntax divided

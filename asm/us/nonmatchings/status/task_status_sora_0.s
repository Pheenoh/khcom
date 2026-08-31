.syntax unified
	.align 2, 0
	.global task_status_sora_0
	.thumb
	.thumb_func
	.type task_status_sora_0, %function
task_status_sora_0: @ 080D7CB0
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _080D7CF0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D7D04
	movs r0, #0x80
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080D7CF4 @ =0x09618118
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r0, [r5, #0x00]
	ldr r1, _080D7CF8 @ =0x0891ED26
	bl func_08002A10
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r1, _080D7CFC @ =0x09EDF38C
	ldr r2, _080D7D00 @ =0x09EDF374
	adds r0, r4, #0x0
	bl AnimInit
	b _080D7D30
	.byte 0x00, 0x00
_080D7CF0: .4byte 0x02039BB0
_080D7CF4: .4byte 0x09618118
_080D7CF8: .4byte 0x0891ED26
_080D7CFC: .4byte 0x09EDF38C
_080D7D00: .4byte 0x09EDF374
_080D7D04:
	movs r0, #0xA0
	lsls r0, r0, #0x03
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080D7D48 @ =0x08F683A4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r0, [r5, #0x00]
	ldr r1, _080D7D4C @ =0x088E33C2
	bl func_08002A10
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r1, _080D7D50 @ =0x09EDEE14
	ldr r2, _080D7D54 @ =0x09EDEE08
	adds r0, r4, #0x0
	bl AnimInit
_080D7D30:
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x08]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D7D48: .4byte 0x08F683A4
_080D7D4C: .4byte 0x088E33C2
_080D7D50: .4byte 0x09EDEE14
_080D7D54: .4byte 0x09EDEE08
.syntax divided

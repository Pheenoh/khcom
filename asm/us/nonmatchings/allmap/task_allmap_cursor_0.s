.syntax unified
	.align 2, 0
	.global task_allmap_cursor_0
	.thumb
	.thumb_func
	.type task_allmap_cursor_0, %function
task_allmap_cursor_0: @ 080D3B1C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x30]
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3BB0 @ =0x0203C540
	ldrh r0, [r0, #0x00]
	subs r0, #0x10
	subs r1, r1, r0
	movs r6, #0x00
	strh r1, [r4, #0x24]
	ldrh r0, [r4, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3BB4 @ =0x0203C53C
	ldrh r0, [r0, #0x00]
	subs r0, #0x0B
	subs r1, r1, r0
	strh r1, [r4, #0x26]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	negs r0, r0
	lsls r0, r0, #0x08
	str r0, [r4, #0x28]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x2C]
	movs r1, #0x24
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x3C]
	str r0, [r4, #0x34]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x40]
	str r0, [r4, #0x38]
	ldr r0, _080D3BB8 @ =0x0976D7C0
	movs r1, #0xC0
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D3BBC @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x0C
	ldr r1, _080D3BC0 @ =0x09EF64C4
	ldr r2, _080D3BC4 @ =0x09EF64B4
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	bl func_08005AFC
	str r0, [r4, #0x08]
	adds r4, #0x44
	strh r6, [r4, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3BB0: .4byte 0x0203C540
_080D3BB4: .4byte 0x0203C53C
_080D3BB8: .4byte 0x0976D7C0
_080D3BBC: .4byte 0x0984A1D8
_080D3BC0: .4byte 0x09EF64C4
_080D3BC4: .4byte 0x09EF64B4
.syntax divided

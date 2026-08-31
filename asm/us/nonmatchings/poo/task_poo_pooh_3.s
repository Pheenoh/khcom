.syntax unified
	.align 2, 0
	.global task_poo_pooh_3
	.thumb
	.thumb_func
	.type task_poo_pooh_3, %function
task_poo_pooh_3: @ 080C9CC8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080C9CE8 @ =0x02034DAC
	ldr r2, [r0, #0x00]
	adds r3, r0, #0x0
	cmp r2, #0x16
	bne _080C9CEC
	movs r0, #0x00
	str r0, [r3, #0x00]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x2C]
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r0, r1
	str r0, [r4, #0x2C]
	b _080C9CFE
_080C9CE8: .4byte 0x02034DAC
_080C9CEC:
	cmp r2, #0x0E
	bne _080C9CFE
	movs r0, #0x00
	str r0, [r3, #0x00]
	ldr r1, _080C9D38 @ =0x0007F700
	str r1, [r4, #0x28]
	ldr r1, _080C9D3C @ =0x00047E00
	str r1, [r4, #0x2C]
	str r0, [r4, #0x30]
_080C9CFE:
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r3, #0x00]
	bl func_080D2C8C
	ldr r0, _080C9D40 @ =0x0203C3E4
	ldrh r0, [r0, #0x00]
	ldr r1, _080C9D44 @ =0x0203C3E0
	ldrh r1, [r1, #0x00]
	bl func_080D2CC4
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x4C
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xB0
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C9D38: .4byte 0x0007F700
_080C9D3C: .4byte 0x00047E00
_080C9D40: .4byte 0x0203C3E4
_080C9D44: .4byte 0x0203C3E0
.syntax divided

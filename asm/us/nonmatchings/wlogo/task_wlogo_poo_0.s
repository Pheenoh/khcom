.syntax unified
	.align 2, 0
	.global task_wlogo_poo_0
	.thumb
	.thumb_func
	.type task_wlogo_poo_0, %function
task_wlogo_poo_0: @ 080B6A74
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080B6AC0 @ =0x096FAE64
	movs r0, #0x00
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B6AC4 @ =0x09648484
	movs r2, #0xA2
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B6AC8 @ =0x096BD464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	movs r0, #0x00
	movs r1, #0x00
	strh r1, [r4, #0x02]
	strb r0, [r4, #0x00]
	strb r0, [r4, #0x08]
	strb r0, [r4, #0x04]
	strh r1, [r4, #0x06]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl SetBgBlend
	ldr r0, _080B6ACC @ =0x02034C98
	movs r1, #0x04
	bl TaskPoolInit
	pop {r4}
	pop {r0}
	bx r0
_080B6AC0: .4byte 0x096FAE64
_080B6AC4: .4byte 0x09648484
_080B6AC8: .4byte 0x096BD464
_080B6ACC: .4byte 0x02034C98
.syntax divided

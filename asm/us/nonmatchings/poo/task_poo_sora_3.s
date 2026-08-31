.syntax unified
	.align 2, 0
	.global task_poo_sora_3
	.thumb
	.thumb_func
	.type task_poo_sora_3, %function
task_poo_sora_3: @ 080CBA08
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080CBA44 @ =0x0203C420
	bl func_080D2D0C
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0x24
	bl TaskPoolDestroy
	ldr r0, _080CBA48 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	bl EwramFree
	adds r0, r4, #0x0
	adds r0, #0xB0
	bl func_080CCBD4
	pop {r4}
	pop {r0}
	bx r0
_080CBA44: .4byte 0x0203C420
_080CBA48: .4byte 0x02039BA0
.syntax divided

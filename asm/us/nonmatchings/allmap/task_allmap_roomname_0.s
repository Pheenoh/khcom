.syntax unified
	.align 2, 0
	.global task_allmap_roomname_0
	.thumb
	.thumb_func
	.type task_allmap_roomname_0, %function
task_allmap_roomname_0: @ 080D3E14
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r1, #0x18
	bl func_08065ACC
	ldrb r0, [r4, #0x00]
	bl func_08093C18
	adds r1, r5, #0x0
	bl func_08065B6C
	adds r6, r5, #0x0
	adds r6, #0xCC
	strb r0, [r6, #0x00]
	ldrb r0, [r4, #0x00]
	bl _080D3DCC
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080D3E78 @ =0x0984A1F8
	adds r0, r4, r0
	movs r1, #0x20
	bl func_08002A14
	adds r1, r5, #0x0
	adds r1, #0xC8
	str r0, [r1, #0x00]
	ldr r0, _080D3E7C @ =0x0984A078
	adds r4, r4, r0
	ldr r1, _080D3E80 @ =0x05000160
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_08005BE8
	ldrb r1, [r6, #0x00]
	adds r0, r5, #0x0
	bl func_08065B08
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080D3D40
	adds r5, #0xCE
	strh r0, [r5, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3E78: .4byte 0x0984A1F8
_080D3E7C: .4byte 0x0984A078
_080D3E80: .4byte 0x05000160
.syntax divided

.syntax unified
	.align 2, 0
	.global task_allmap_room_0
	.thumb
	.thumb_func
	.type task_allmap_room_0, %function
task_allmap_room_0: @ 080D37EC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldrh r2, [r1, #0x00]
	adds r0, #0x8C
	strh r2, [r0, #0x00]
	ldrh r0, [r1, #0x02]
	adds r2, r5, #0x0
	adds r2, #0x8E
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldrh r0, [r1, #0x02]
	negs r0, r0
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldrh r0, [r1, #0x02]
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldrb r2, [r1, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x98
	strb r2, [r0, #0x00]
	ldrh r0, [r1, #0x06]
	adds r4, r5, #0x0
	adds r4, #0x9C
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_080D35B0
	adds r6, r5, #0x0
	adds r6, #0x9A
	strh r0, [r6, #0x00]
	ldrh r4, [r4, #0x00]
	cmp r4, #0x00
	bne _080D3848
	ldr r0, _080D3844 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl LoadObjTiles
	str r0, [r5, #0x00]
	str r4, [r5, #0x08]
	b _080D3868
	.byte 0x00, 0x00
_080D3844: .4byte 0x0976B340
_080D3848:
	ldr r4, _080D3884 @ =0x09EF6424
	adds r0, r4, #0x0
	movs r1, #0x11
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D3888 @ =0x0976B340
	bl AllocObjTiles
	str r0, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
_080D3868:
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0x98
	cmp r0, #0x00
	bne _080D3894
	ldr r1, _080D388C @ =0x0203C590
	ldrb r0, [r2, #0x00]
	ldrb r1, [r1, #0x06]
	cmp r0, r1
	bne _080D3894
	ldr r0, _080D3890 @ =0x0984A138
	b _080D389E
_080D3884: .4byte 0x09EF6424
_080D3888: .4byte 0x0976B340
_080D388C: .4byte 0x0203C590
_080D3890: .4byte 0x0984A138
_080D3894:
	ldrb r0, [r2, #0x00]
	bl func_080D37BC
	ldr r1, _080D38AC @ =0x0984A0F8
	adds r0, r0, r1
_080D389E:
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D38AC: .4byte 0x0984A0F8
.syntax divided

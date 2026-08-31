.syntax unified
	.align 2, 0
	.global task_poo_map_0
	.thumb
	.thumb_func
	.type task_poo_map_0, %function
task_poo_map_0: @ 080CA0CC
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	add sp, #-0x014
	adds r6, r0, #0x0
	bl func_080CA0A8
	bl func_080CA0C0
	add r1, sp, #0x010
	mov r0, sp
	bl func_080D2CA8
	ldr r0, _080CA1E0 @ =0x0203C3EC
	mov r1, sp
	str r1, [r0, #0x00]
	bl func_080C9FBC
	ldr r2, _080CA1E4 @ =0x02034DE4
	ldr r0, _080CA1E8 @ =0x0203C408
	ldr r1, [r0, #0x00]
	str r1, [r2, #0x00]
	ldr r2, _080CA1EC @ =0x0203C40C
	mov r9, r2
	ldr r0, _080CA1F0 @ =0x0203C3FC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r0, #0x78
	strh r0, [r2, #0x00]
	ldr r0, _080CA1F4 @ =0x0203C3F8
	mov r8, r0
	asrs r1, r1, #0x08
	subs r1, #0x50
	strh r1, [r0, #0x00]
	ldr r0, _080CA1F8 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	mov r2, r8
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r5, _080CA1FC @ =0x096FC6E0
	ldrb r0, [r5, #0x16]
	strb r0, [r6, #0x00]
	ldrb r0, [r5, #0x17]
	strb r0, [r6, #0x01]
	adds r4, r6, #0x4
	adds r0, r4, #0x0
	movs r1, #0xB2
	bl TaskPoolInit
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_080C9EFC
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_080C9EAC
	adds r0, r4, #0x0
	bl func_080C9E84
	ldr r1, _080CA200 @ =0x09EF49E8
	adds r0, r4, #0x0
	movs r2, #0x00
	bl TaskCreate
	ldr r1, [r5, #0x00]
	ldrh r2, [r5, #0x04]
	movs r0, #0x03
	bl LoadBgTiles
	ldr r1, [r5, #0x10]
	ldrh r2, [r5, #0x14]
	movs r0, #0x02
	bl LoadBgTiles
	ldr r1, [r5, #0x08]
	ldrh r2, [r5, #0x0C]
	movs r0, #0x03
	bl LoadBgPalette
	ldr r1, _080CA204 @ =0x09EF4208
	ldrb r2, [r6, #0x00]
	ldrb r3, [r6, #0x01]
	movs r0, #0x03
	bl func_0800516C
	mov r0, r9
	ldrh r1, [r0, #0x00]
	mov r0, r8
	ldrh r2, [r0, #0x00]
	movs r0, #0x03
	bl func_080051C4
	bl func_080CA35C
	ldr r1, _080CA208 @ =0x09EF4448
	ldrb r2, [r6, #0x00]
	ldrb r3, [r6, #0x01]
	movs r0, #0x01
	bl func_0800516C
	mov r2, r9
	ldrh r1, [r2, #0x00]
	mov r0, r8
	ldrh r2, [r0, #0x00]
	movs r0, #0x01
	bl func_080051C4
	ldr r1, _080CA20C @ =0x09EF4688
	ldrb r2, [r6, #0x00]
	ldrb r3, [r6, #0x01]
	movs r0, #0x02
	bl func_0800516C
	mov r2, r9
	ldrh r1, [r2, #0x00]
	mov r0, r8
	ldrh r2, [r0, #0x00]
	movs r0, #0x02
	bl func_080051C4
	bl func_0802F1C8
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CA1E0: .4byte 0x0203C3EC
_080CA1E4: .4byte 0x02034DE4
_080CA1E8: .4byte 0x0203C408
_080CA1EC: .4byte 0x0203C40C
_080CA1F0: .4byte 0x0203C3FC
_080CA1F4: .4byte 0x0203C3F8
_080CA1F8: .4byte 0x02039BA0
_080CA1FC: .4byte 0x096FC6E0
_080CA200: .4byte 0x09EF49E8
_080CA204: .4byte 0x09EF4208
_080CA208: .4byte 0x09EF4448
_080CA20C: .4byte 0x09EF4688
.syntax divided

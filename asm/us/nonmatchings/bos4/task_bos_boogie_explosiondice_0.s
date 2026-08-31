.syntax unified
	.align 2, 0
	.global task_bos_boogie_explosiondice_0
	.thumb
	.thumb_func
	.type task_bos_boogie_explosiondice_0, %function
task_bos_boogie_explosiondice_0: @ 080DA508
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	movs r0, #0x00
	str r0, [r6, #0x00]
	strh r0, [r6, #0x04]
	subs r2, #0x0C
	adds r1, r6, r2
	str r0, [r1, #0x00]
	bl GetRandom
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r4, r6, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, #0x61
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x4C
	str r0, [r4, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x7F
	ands r0, r1
	adds r0, #0x40
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	strb r0, [r1, #0x00]
	ldr r0, _080DA5D4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x44]
	ldr r0, [r1, #0x08]
	str r0, [r6, #0x48]
	ldr r0, _080DA5D8 @ =0xFFFF6000
	str r0, [r6, #0x4C]
	adds r0, r6, #0x0
	adds r0, #0x80
	ldr r1, _080DA5DC @ =0x096FDFC4
	ldrh r2, [r1, #0x08]
	ldrh r3, [r1, #0x06]
	movs r1, #0x08
	bl func_080122AC
	ldr r5, _080DA5E0 @ =0x09EF6774
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DA5E4 @ =0x0979666A
	bl AllocObjTiles
	str r0, [r6, #0x08]
	ldr r0, _080DA5E8 @ =0x0984AF98
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x0C]
	ldr r0, _080DA5EC @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x10]
	adds r4, r6, #0x0
	adds r4, #0x14
	ldr r1, _080DA5F0 @ =0x09EF6784
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080DA5F4 @ =0x09EDB350
	adds r2, r6, #0x0
	adds r2, #0x40
	adds r0, r4, #0x0
	bl TaskCreate
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DA5D4: .4byte 0x02039B84
_080DA5D8: .4byte 0xFFFF6000
_080DA5DC: .4byte 0x096FDFC4
_080DA5E0: .4byte 0x09EF6774
_080DA5E4: .4byte 0x0979666A
_080DA5E8: .4byte 0x0984AF98
_080DA5EC: .4byte 0x08F69BC4
_080DA5F0: .4byte 0x09EF6784
_080DA5F4: .4byte 0x09EDB350
.syntax divided

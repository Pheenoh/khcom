.syntax unified
	.align 2, 0
	.global mode_mapinspect_0
	.thumb
	.thumb_func
	.type mode_mapinspect_0, %function
mode_mapinspect_0: @ 08108CE8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08108DB4 @ =0x02035E28
	movs r0, #0xBD
	lsls r0, r0, #0x02
	bl EwramAlloc
	str r0, [r4, #0x00]
	bl func_08001F98
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x1E
	movs r3, #0x0F
	bl SetupBg
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	movs r1, #0x03
	bl SetBgPriority
	movs r0, #0x01
	movs r1, #0x02
	bl SetBgPriority
	movs r0, #0x02
	movs r1, #0x01
	bl SetBgPriority
	movs r0, #0x03
	movs r1, #0x00
	bl SetBgPriority
	bl func_08107B84
	ldr r0, _08108DB8 @ =0x02035FCA
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r1, _08108DBC @ =0x02035FCC
	movs r0, #0x10
	strh r0, [r1, #0x00]
	ldr r1, _08108DC0 @ =0x02035FD0
	ldr r0, _08108DC4 @ =0xFFFFF800
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r1, _08108DC8 @ =0x02035FD8
	ldr r0, _08108DCC @ =0xFFFF8000
	str r0, [r1, #0x00]
	ldr r1, _08108DD0 @ =0x02035E2E
	movs r0, #0x04
	strh r0, [r1, #0x00]
	ldr r0, _08108DD4 @ =0x02035E98
	strh r2, [r0, #0x00]
	ldr r0, _08108DD8 @ =0x02035E9A
	strh r2, [r0, #0x00]
	ldr r0, _08108DDC @ =0x02035E9C
	strh r2, [r0, #0x00]
	ldr r0, _08108DE0 @ =0x02035E48
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _08108DF4
	ldr r1, _08108DE4 @ =0x02035FDC
	movs r2, #0x00
	ldr r0, _08108DE8 @ =0xFFFFFE00
	str r0, [r1, #0x00]
	ldr r1, _08108DEC @ =0x02035FE0
	movs r0, #0x80
	lsls r0, r0, #0x05
	str r0, [r1, #0x00]
	ldr r0, _08108DF0 @ =0x02035E2C
	strh r2, [r0, #0x00]
	b _08108E14
	.byte 0x00, 0x00
_08108DB4: .4byte 0x02035E28
_08108DB8: .4byte 0x02035FCA
_08108DBC: .4byte 0x02035FCC
_08108DC0: .4byte 0x02035FD0
_08108DC4: .4byte 0xFFFFF800
_08108DC8: .4byte 0x02035FD8
_08108DCC: .4byte 0xFFFF8000
_08108DD0: .4byte 0x02035E2E
_08108DD4: .4byte 0x02035E98
_08108DD8: .4byte 0x02035E9A
_08108DDC: .4byte 0x02035E9C
_08108DE0: .4byte 0x02035E48
_08108DE4: .4byte 0x02035FDC
_08108DE8: .4byte 0xFFFFFE00
_08108DEC: .4byte 0x02035FE0
_08108DF0: .4byte 0x02035E2C
_08108DF4:
	ldr r2, _08108EF4 @ =0x02035FDC
	ldr r0, _08108EF8 @ =0x09EF9618
	movs r3, #0x24
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x09
	ldr r1, _08108EFC @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _08108F00 @ =0x02035FE0
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r1, _08108F04 @ =0x02035E2C
	movs r0, #0x01
	strh r0, [r1, #0x00]
_08108E14:
	movs r1, #0x00
	ldr r3, _08108F08 @ =0x02035ED0
	mov r10, r3
	ldr r0, _08108F0C @ =0x02035F00
	mov r9, r0
	ldr r3, _08108F10 @ =0x02035EA0
	mov r8, r3
	movs r5, #0x00
	ldr r0, _08108F14 @ =0x02035F30
	mov r12, r0
_08108E28:
	movs r3, #0x00
	lsls r7, r1, #0x10
	asrs r1, r7, #0x10
	lsls r0, r1, #0x01
	adds r4, r0, r1
	lsls r6, r4, #0x02
_08108E34:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #0x02
	adds r0, r0, r6
	mov r3, r8
	adds r1, r0, r3
	str r5, [r1, #0x00]
	mov r3, r10
	adds r1, r0, r3
	str r5, [r1, #0x00]
	add r0, r9
	str r5, [r0, #0x00]
	adds r0, r2, r4
	add r0, r12
	strb r5, [r0, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x02
	ble _08108E34
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r7, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08108E28
	movs r0, #0x00
	ldr r3, _08108F18 @ =0x02035F3C
	str r0, [r3, #0x00]
	ldr r1, _08108F1C @ =0x02035F40
	str r0, [r1, #0x00]
	ldr r3, _08108F20 @ =0x02035F44
	str r0, [r3, #0x00]
	ldr r1, _08108F24 @ =0x02035F48
	str r0, [r1, #0x00]
	ldr r3, _08108F28 @ =0x02035F4C
	str r0, [r3, #0x00]
	ldr r1, _08108F2C @ =0x02035F50
	str r0, [r1, #0x00]
	ldr r3, _08108F30 @ =0x02035F90
	strb r0, [r3, #0x00]
	ldr r1, _08108F34 @ =0x02035E74
	str r0, [r1, #0x00]
	ldr r3, _08108F38 @ =0x02035FC4
	strh r0, [r3, #0x00]
	ldr r1, _08108F3C @ =0x02035FC6
	strh r0, [r1, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	ldr r1, _08108F40 @ =0x09A3D0DC
	bl LoadBgPalette
	ldr r1, _08108F44 @ =0x09A03CFC
	movs r2, #0xA6
	lsls r2, r2, #0x06
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _08108F48 @ =0x09611AB8
	movs r0, #0x02
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _08108F4C @ =0x099597E4
	movs r2, #0xA0
	lsls r2, r2, #0x01
	movs r0, #0x02
	bl LoadBgTiles
	ldr r1, _08108F50 @ =0x09985F44
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl LoadBgMap
	ldr r1, _08108F54 @ =0x09A3439C
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x00
	adds r2, r4, #0x0
	bl LoadBgMap
	bl func_0810718C
	ldrh r0, [r0, #0x04]
	cmp r0, #0x03
	bne _08108F5C
	ldr r1, _08108F58 @ =0x09A3551C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
	b _08108F66
	.byte 0x00, 0x00
_08108EF4: .4byte 0x02035FDC
_08108EF8: .4byte 0x09EF9618
_08108EFC: .4byte 0xFFFFFF00
_08108F00: .4byte 0x02035FE0
_08108F04: .4byte 0x02035E2C
_08108F08: .4byte 0x02035ED0
_08108F0C: .4byte 0x02035F00
_08108F10: .4byte 0x02035EA0
_08108F14: .4byte 0x02035F30
_08108F18: .4byte 0x02035F3C
_08108F1C: .4byte 0x02035F40
_08108F20: .4byte 0x02035F44
_08108F24: .4byte 0x02035F48
_08108F28: .4byte 0x02035F4C
_08108F2C: .4byte 0x02035F50
_08108F30: .4byte 0x02035F90
_08108F34: .4byte 0x02035E74
_08108F38: .4byte 0x02035FC4
_08108F3C: .4byte 0x02035FC6
_08108F40: .4byte 0x09A3D0DC
_08108F44: .4byte 0x09A03CFC
_08108F48: .4byte 0x09611AB8
_08108F4C: .4byte 0x099597E4
_08108F50: .4byte 0x09985F44
_08108F54: .4byte 0x09A3439C
_08108F58: .4byte 0x09A3551C
_08108F5C:
	ldr r1, _08109120 @ =0x09A3501C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl LoadBgMap
_08108F66:
	ldr r0, _08109124 @ =0x02035E2E
	movs r3, #0x00
	ldsh r0, [r0, r3]
	bl func_081078F0
	bl func_081075FC
	bl func_0810764C
	bl func_081076D4
	ldr r5, _08109128 @ =0x09A3D2DC
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _0810912C @ =0x02035E4C
	str r0, [r1, #0x00]
	ldr r0, _08109130 @ =0x0999DAEC
	movs r1, #0xAC
	lsls r1, r1, #0x04
	bl LoadObjTiles
	ldr r1, _08109134 @ =0x02035E50
	str r0, [r1, #0x00]
	ldr r4, _08109138 @ =0x02035E58
	ldr r1, _0810913C @ =0x09EF981C
	ldr r2, _08109140 @ =0x09EF97EC
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, _08109144 @ =0x0999E69E
	movs r1, #0xD6
	lsls r1, r1, #0x04
	bl LoadObjTiles
	ldr r1, _08109148 @ =0x02035E78
	str r0, [r1, #0x00]
	ldr r4, _0810914C @ =0x02035E80
	ldr r1, _08109150 @ =0x09EF9858
	ldr r2, _08109154 @ =0x09EF9830
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _08109158 @ =0x02035E70
	str r0, [r1, #0x00]
	ldr r0, _0810915C @ =0x0908B1B4
	movs r1, #0x9A
	lsls r1, r1, #0x04
	bl LoadObjTiles
	ldr r1, _08109160 @ =0x02035F54
	str r0, [r1, #0x00]
	ldr r4, _08109164 @ =0x02035F58
	ldr r1, _08109168 @ =0x09EEA164
	ldr r2, _0810916C @ =0x09EEA148
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, _08109170 @ =0x0908C3CE
	movs r1, #0x98
	lsls r1, r1, #0x02
	bl LoadObjTiles
	ldr r1, _08109174 @ =0x02035F70
	str r0, [r1, #0x00]
	ldr r4, _08109178 @ =0x02035F78
	ldr r1, _0810917C @ =0x09EEA198
	ldr r2, _08109180 @ =0x09EEA180
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r4, _08109184 @ =0x02035F94
	movs r0, #0x90
	lsls r0, r0, #0x01
	bl EwramAlloc
	str r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065ACC
	ldr r4, _08109188 @ =0x02035F9C
	movs r0, #0xB4
	lsls r0, r0, #0x02
	bl EwramAlloc
	str r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065ACC
	ldr r6, _0810918C @ =0x08159FBC
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08109190 @ =0x02035FAA
	strh r0, [r4, #0x00]
	ldr r5, _08109194 @ =0x02035FA4
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl EwramAlloc
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08109198 @ =0x02035FA8
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _0810919C @ =0x08159E10
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091A0 @ =0x02035FB2
	strh r0, [r4, #0x00]
	ldr r5, _081091A4 @ =0x02035FAC
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl EwramAlloc
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _081091A8 @ =0x02035FB0
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _081091AC @ =0x08159E18
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091B0 @ =0x02035FBA
	strh r0, [r4, #0x00]
	ldr r5, _081091B4 @ =0x02035FB4
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl EwramAlloc
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _081091B8 @ =0x02035FB8
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _081091BC @ =0x0815C136
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091C0 @ =0x02035FC2
	strh r0, [r4, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl EwramAlloc
	ldr r5, _081091C4 @ =0x02035FBC
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	ldr r1, _081091C8 @ =0x02035FC0
	strb r0, [r1, #0x00]
	bl func_08107280
	bl func_081073F0
	movs r0, #0x00
	bl EnableBg
	movs r0, #0x01
	bl EnableBg
	movs r0, #0x02
	bl DisableBg
	movs r0, #0x03
	bl DisableBg
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08109120: .4byte 0x09A3501C
_08109124: .4byte 0x02035E2E
_08109128: .4byte 0x09A3D2DC
_0810912C: .4byte 0x02035E4C
_08109130: .4byte 0x0999DAEC
_08109134: .4byte 0x02035E50
_08109138: .4byte 0x02035E58
_0810913C: .4byte 0x09EF981C
_08109140: .4byte 0x09EF97EC
_08109144: .4byte 0x0999E69E
_08109148: .4byte 0x02035E78
_0810914C: .4byte 0x02035E80
_08109150: .4byte 0x09EF9858
_08109154: .4byte 0x09EF9830
_08109158: .4byte 0x02035E70
_0810915C: .4byte 0x0908B1B4
_08109160: .4byte 0x02035F54
_08109164: .4byte 0x02035F58
_08109168: .4byte 0x09EEA164
_0810916C: .4byte 0x09EEA148
_08109170: .4byte 0x0908C3CE
_08109174: .4byte 0x02035F70
_08109178: .4byte 0x02035F78
_0810917C: .4byte 0x09EEA198
_08109180: .4byte 0x09EEA180
_08109184: .4byte 0x02035F94
_08109188: .4byte 0x02035F9C
_0810918C: .4byte 0x08159FBC
_08109190: .4byte 0x02035FAA
_08109194: .4byte 0x02035FA4
_08109198: .4byte 0x02035FA8
_0810919C: .4byte 0x08159E10
_081091A0: .4byte 0x02035FB2
_081091A4: .4byte 0x02035FAC
_081091A8: .4byte 0x02035FB0
_081091AC: .4byte 0x08159E18
_081091B0: .4byte 0x02035FBA
_081091B4: .4byte 0x02035FB4
_081091B8: .4byte 0x02035FB8
_081091BC: .4byte 0x0815C136
_081091C0: .4byte 0x02035FC2
_081091C4: .4byte 0x02035FBC
_081091C8: .4byte 0x02035FC0
.syntax divided
